/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:56:07 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 01:37:01 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const t_builtin	g_builtin_list[7] = {
	{"echo", &builtin_echo},
	{"cd", &builtin_cd},
	{"pwd", &builtin_pwd},
	{"export", &builtin_export},
	{"unset", &builtin_unset},
	{"env", &builtin_env},
	{"exit", &builtin_exit}
};

static void	restore_fd(t_shell *shell)
{
	if (dup2(shell->io_save[0], STDIN_FILENO) == -1)
		ft_perror("dup2 error");
	if (dup2(shell->io_save[1], STDOUT_FILENO) == -1)
		return (ft_perror("dup2 error"));
	if (close(shell->cmd[0].io[1]) == -1)
		ft_perror("close error");
	if (close(shell->io_save[0]) == -1)
		ft_perror("close error");
	if (close(shell->io_save[1]) == -1)
		ft_perror("close error");
}

void	execute_builtin(t_shell *shell, char **cmd)
{
	size_t	i;

	i = -1;
	if (!cmd[0])
		return ;
	while (++i < 7)
	{
		if (ft_strncmp(*cmd, g_builtin_list[i].name, \
		ft_strlen(g_builtin_list[i].name) + 1) == 0)
		{
			if (shell->nbcmd != 1)
				exit(g_builtin_list[i].function(shell, cmd));
			if (shell->cmd[0].io[1] > 2)
				if (dup2(shell->cmd[0].io[1], STDOUT_FILENO) == -1)
					return (perror("dup2 error"));
			g_status = g_builtin_list[i].function(shell, cmd);
			if (shell->cmd[0].io[1] > 2)
				restore_fd(shell);
			return ;
		}
	}
}
