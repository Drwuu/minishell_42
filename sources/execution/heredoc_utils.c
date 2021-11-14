/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:11:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 02:42:56 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_heredoc(char **heredoc, char *line)
{
	char	*dupline;
	char	*dupline_nl;

	dupline = strdup_shell(line);
	if (!dupline)
		ft_perror("strdup error");
	dupline_nl = strjoin_shell(dupline, "\n");
	free(dupline);
	if (!dupline_nl)
		ft_perror("strjoin error");
	dupline = strdup_shell(*heredoc);
	if (!dupline)
		ft_perror("strdup error");
	*heredoc = strjoin_shell(dupline, dupline_nl);
	free(dupline);
	free(dupline_nl);
	if (!*heredoc)
		ft_perror("strjoin error");
}

void	exit_heredoc(char *line, char *heredoc, int exit_status, int fd[2])
{
	if (heredoc)
		free(heredoc);
	if (line)
		free(line);
	if (close(fd[1]) == -1)
		ft_perror("close error");
	exit(exit_status);
}

void	write_heredoc(char *line, char *heredoc, int fd[2])
{
	ft_putstr_fd(heredoc, fd[1]);
	exit_heredoc(line, heredoc, EXIT_SUCCESS, fd);
}
