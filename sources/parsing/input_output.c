/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:45:26 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/13 04:35:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_create_file(t_shell *minis, char *file, int oflag, int cmd)
{
	int	fd;
	int	io;

	fd = 0;
	io = STDIN_FILENO;
	if (oflag == (O_WRONLY | O_CREAT | O_TRUNC) || \
	oflag == (O_WRONLY | O_CREAT | O_APPEND))
		io = STDOUT_FILENO;
	if (minis->cmd[cmd].io[io] != 0)
		close(minis->cmd[cmd].io[io]);
	fd = open(file, oflag, 0777);
	if (fd < 0)
		perror("minishell ");
	minis->cmd[cmd].io[io] = fd;
	return (fd);
}

int	del_quote(t_shell *minis, int i, int len)
{
	minis->mask = ft_strdel(minis->mask, i + len);
	minis->line = ft_strdel(minis->line, i + len);
	if (minis->mask[i + len - 1] != SEP)
		len--;
	return (len);
}

int	parse_input_output(t_shell *minis, int i, int cmd, int oflag)
{
	char	*file;
	int		len;

	file = NULL;
	len = 0;
	while (minis->mask[i] != TODEL && minis->mask[i] != OPTION)
		i++;
	if (minis->mask[i] == TODEL && minis->mask[i + 1] == TODEL)
		open_create_file(minis, "", oflag, cmd);
	else
	{
		while (minis->mask[i + len] && minis->mask[i + len] != SEP)
		{
			if (minis->mask[i + len] == TODEL)
				len = del_quote(minis, i, len);
			minis->mask[i + len] = FILES;
			len++;
		}
		file = ft_substr(minis->line, i, len);
		if (open_create_file(minis, file, oflag, cmd) < 0)
			return (-1);
		i += len - 1;
		len = 0;
	}
	return (i);
}

int	mask_heredoc(t_shell *minis, int i)
{
	if (minis->mask[i] == DREDIR)
		i += 3;
	while (minis->mask[i] && minis->mask[i] != SEP)
	{
		if (minis->mask[i] != TODEL)
			minis->mask[i] = FILES;
		i++;
	}
	if (minis->mask[i] == '\0')
		i--;
	return (i);
}

int	check_input_output(t_shell *minis, char *mask)
{
	int		i;
	size_t	cmd;
	int		*io;

	i = 0;
	cmd = 0;
	io = minis->cmd[cmd].io;
	while (mask[i])
	{
		if (mask[i] == EOCP)
			io = minis->cmd[++cmd].io;
		if (mask[i] == SREDIR && io[1] >= 0 && io[0] >= 0)
			i = parse_input_output(minis, i, cmd, O_WRONLY | O_CREAT | O_TRUNC);
		else if (mask[i] == SSREDIR && io[1] >= 0 && io[0] >= 0)
			i = parse_input_output(minis, i, cmd, \
			O_WRONLY | O_CREAT | O_APPEND);
		else if (mask[i] == FREDIR && io[1] >= 0 && io[0] >= 0)
			i = parse_input_output(minis, i, cmd, O_RDONLY);
		else if (mask[i] == DREDIR)
			i = mask_heredoc(minis, i);
		if (i == -1)
			return (-1);
		i++;
	}
	return (0);
}
