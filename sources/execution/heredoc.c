/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:11:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 03:17:43 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct heredoc
{
	char	*line;
	char	*heredoc;
	int		i;
}	t_heredoc;

static void	process(t_shell *shell, t_heredoc *heredoc, int fd[2])
{
	if (heredoc->i == ft_strlen_dbl_array(shell->heredoc) - 1)
	{
		if (ft_strncmp(shell->heredoc[heredoc->i], heredoc->line, \
		ft_strlen(shell->heredoc[heredoc->i]) + 1))
			fill_heredoc(&heredoc->heredoc, heredoc->line);
		else
		{
			if (!shell->cmd[0].cmd[0])
				exit_heredoc(heredoc->line, heredoc->heredoc, EXIT_SUCCESS, fd);
			write_heredoc(heredoc->line, heredoc->heredoc, fd);
		}
	}
	else if (!ft_strncmp(shell->heredoc[heredoc->i], heredoc->line, \
	ft_strlen(shell->heredoc[heredoc->i]) + 1))
		heredoc->i++;
}

static void	exec_heredoc(t_shell *shell, int fd[2])
{
	t_heredoc	heredoc;

	heredoc.i = 0;
	heredoc.line = NULL;
	heredoc.heredoc = strdup_shell("");
	if (!heredoc.heredoc)
		ft_perror("strdup error");
	if (close(fd[0]) == -1)
		ft_perror("close error");
	while (TRUE)
	{
		heredoc.line = readline("> ");
		if (heredoc.line == NULL)
			exit_heredoc(heredoc.line, heredoc.heredoc, EXIT_SUCCESS, fd);
		if (heredoc.line[0] != 0)
			process(shell, &heredoc, fd);
		if (heredoc.line)
			free(heredoc.line);
	}
}

static void	parent(t_shell *shell, pid_t pid, int fd[2])
{
	if (close(fd[1]) == -1)
		perror("close error");
	if (shell->cmd[0].cmd[0])
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror("dup2 error");
	if (waitpid(pid, &g_status, 0) == -1)
		perror("waitpid error");
	if (WIFEXITED(g_status))
		g_status = WEXITSTATUS(g_status);
	else if (WIFSIGNALED(g_status))
	{
		if (dup2(shell->io_save[0], STDIN_FILENO) == -1)
			ft_perror("dup2 error");
		if (dup2(shell->io_save[1], STDOUT_FILENO) == -1)
			ft_perror("dup2 error");
		if (g_status != 13)
			ft_putstr_fd("\n", 1);
		g_status = WTERMSIG(g_status) + 128;
	}
	if (close(fd[0]) == -1)
		perror("close error");
}

void	heredoc(t_shell *shell)
{
	int		nb_heredoc;
	int		fd[2];
	pid_t	pid;
	int		i;

	i = -1;
	nb_heredoc = ft_strlen_dbl_array(shell->heredoc);
	sigaction(SIGINT, &shell->signal[2], &shell->signal[0]);
	if (nb_heredoc)
	{
		if (pipe(fd) == -1)
			perror("pipe error");
		pid = fork();
		if (pid == -1)
			perror("fork error");
		else if (pid == 0)
		{
			sigaction(SIGINT, &shell->signal[1], NULL);
			exec_heredoc(shell, fd);
		}
		else
			parent(shell, pid, fd);
	}
	sigaction(SIGINT, &shell->signal[0], &shell->signal[1]);
}
