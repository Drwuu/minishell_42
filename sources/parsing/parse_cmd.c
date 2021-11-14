/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:11:25 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/13 04:40:28 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_line_process(t_shell *minis, char *line)
{
	minis->nbcmd = check_nb_cmd(minis, line);
	minis->cmd = wrmalloc((minis->nbcmd + 1) * sizeof(t_cmd));
	ft_bzero(minis->cmd, (minis->nbcmd + 1) * sizeof(t_cmd));
	minis->line = check_sp(minis, line);
	create_mask(minis, minis->line);
	calc_heredoc(minis);
	if (reverse_env(minis) == -1)
		return (-1);
	create_mask_post_env(minis);
	if (check_input_output(minis, minis->mask) == -1)
		return (-1);
	return (0);
}

int	parse_line(t_shell *minis, char *line)
{
	int	ret;

	ret = 0;
	if (*line == 0)
	{
		wrfree(line);
		return (-1);
	}
	if (check_line_valitidy(minis, line) == -1)
		return (-1);
	if (parse_line_process(minis, line) == -1)
		return (-1);
	ret = split_command(minis);
	heredoc(minis);
	if (ret && minis->nbcmd == 1)
	{
		if (minis->cmd[0].io[0] > 0)
			close(minis->cmd[0].io[0]);
		if (minis->cmd[0].io[1] > 0)
			close(minis->cmd[0].io[1]);
		return (-1);
	}
	update_env(minis);
	return (0);
}
