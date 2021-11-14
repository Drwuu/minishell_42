/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:21:59 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 02:05:39 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_input(int last_elem, t_shell *shell, int *fd_pipe, int i)
{
	(void)shell;
	if (close(fd_pipe[1]) == -1)
		perror("close 0 error");
	if (i != last_elem)
	{
		if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
			perror("dup2 error");
		if (close(fd_pipe[0]) == -1)
			perror("close 1 error");
	}
}

void	redirect_output(int last_elem, t_shell *shell, int *fd_pipe, int i)
{
	if (shell->cmd[i].io[0] > 2)
		if (dup2(shell->cmd[i].io[0], STDIN_FILENO) == -1)
			ft_perror("dup2 error");
	if (close(fd_pipe[0]) == -1)
		ft_perror("close 2 error");
	if (i != last_elem)
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			ft_perror("dup2 error");
	if (shell->cmd[i].io[1] > 2)
		if (dup2(shell->cmd[i].io[1], STDOUT_FILENO) == -1)
			ft_perror("dup2 error");
}

static void	wait_childs_process(t_shell *shell, pid_t *pid, int i)
{
	waitpid(pid[i], &g_status, 0);
	if (shell->cmd[i].io[0] > 2)
		if (close(shell->cmd[i].io[0]) == -1)
			perror("close error");
	if (shell->cmd[i].io[1] > 2)
		if (close(shell->cmd[i].io[1]) == -1)
			perror("close error");
	if (WIFEXITED(g_status))
		g_status = WEXITSTATUS(g_status);
	else if (WIFSIGNALED(g_status))
	{
		if (g_status != 13)
			ft_putstr_fd("\n", 1);
		g_status = WTERMSIG(g_status) + 128;
	}
}

void	wait_childs(t_shell *shell, pid_t *pid, int nb_cmd)
{
	int	i;

	i = -1;
	sigaction(SIGINT, &shell->signal[2], &shell->signal[0]);
	if (dup2(shell->io_save[0], STDIN_FILENO) == -1)
		perror("dup2 0 error");
	if (dup2(shell->io_save[1], STDOUT_FILENO) == -1)
		perror("dup2 1 error");
	while (++i < nb_cmd)
		wait_childs_process(shell, pid, i);
	sigaction(SIGINT, &shell->signal[0], &shell->signal[1]);
	if (close(shell->io_save[0]) == -1)
		perror("close 3 error");
	if (close(shell->io_save[1]) == -1)
		perror("close 4 error");
}
