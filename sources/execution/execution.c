/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:41:12 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 01:39:32 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	main_execution(t_shell *shell, t_cmd cmd)
{
	char	**paths;
	char	*binary;

	paths = NULL;
	binary = cmd.cmd[0];
	execute_builtin(shell, cmd.cmd);
	if (binary && !ft_ischar(cmd.cmd[0], '/'))
	{
		paths = ft_split(getenv_name(shell, "PATH"), ":");
		binary = get_binary(cmd.cmd[0], paths);
		ft_free_dbl_array((void **)paths, 0);
		if (!binary)
			binary = ft_strdup("");
	}
	if (binary && execve(binary, cmd.cmd, shell->envp) == -1)
	{
		wrfree(binary);
		ft_perror("execve error");
	}
	exit(EXIT_SUCCESS);
}

static void	child(t_shell *shell, t_cmd cmd, int *fd_pipe, int i)
{
	sigaction(SIGQUIT, &shell->signal[3], &shell->signal[2]);
	redirect_output(shell->nbcmd - 1, shell, fd_pipe, i);
	main_execution(shell, cmd);
}

static void	pipex(t_shell *shell, t_cmd cmd, int i, pid_t *pid)
{
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		perror("pipe error");
	pid[i] = fork();
	if (pid[i] == -1)
		perror("fork error");
	if (pid[i] == 0)
		child(shell, cmd, fd_pipe, i);
	else
		redirect_input(shell->nbcmd - 1, shell, fd_pipe, i);
}

void	execute_commands(t_shell *shell, t_cmd *cmd)
{
	pid_t	*pid;
	int		i;

	pid = NULL;
	i = -1;
	while ((size_t)++i < shell->nbcmd)
		if (cmd[i].io[0] < 0 || cmd[i].io[1] < 0)
			return ;
	if (shell->nbcmd == 1 && cmd[0].is_builtin)
		execute_builtin(shell, cmd[0].cmd);
	else
	{
		i = -1;
		pid = ft_calloc(sizeof(*pid), shell->nbcmd);
		while ((size_t)++i < shell->nbcmd)
			pipex(shell, cmd[i], i, pid);
		wait_childs(shell, pid, shell->nbcmd);
		wrfree(pid);
	}
}
