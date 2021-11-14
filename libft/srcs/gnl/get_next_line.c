/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:01:43 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/30 08:32:19 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line_process(char **str, int fd, char **buf)
{
	int		head;

	head = 1;
	while (head > 0)
	{
		head = read(fd, *buf, BUFFER_SIZE);
		(*buf)[head] = '\0';
		if (copy_line(*buf, str) < 0)
			return (-1);
		if (find_newline(*str) >= 0)
			break ;
	}
	if (head < 0)
		return (-1);
	return (1);
}

static int	read_line(char **str, int fd)
{
	char	*buf;

	buf = wrmalloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free_str_error(*str, buf));
	if (read_line_process(str, fd, &buf) < 0)
		return (free_str_error(*str, buf));
	if (!*str)
	{
		*str = ft_strdup("");
		if (!*str)
			return (free_str_error(*str, buf));
	}
	wrfree(buf);
	return (1);
}

static int	build_line_process(char **str, char **line, char **tmp, int i)
{
	*line = ft_substr(*str, 0, i);
	if (!*line)
		return (-1);
	*tmp = ft_strdup(&(*str)[i + 1]);
	if (!*tmp)
		return (-1);
	wrfree(*str);
	*str = *tmp;
	return (1);
}

static int	build_line(char **str, char **line)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = find_newline(*str);
	if (i >= 0)
	{
		if (build_line_process(str, line, &tmp, i) < 0)
			return (free_str_error(*str, tmp));
		return (1);
	}
	else
	{
		*line = ft_substr(*str, 0, ft_strlen(*str));
		if (!*line)
			return (free_str_error(*str, tmp));
		wrfree(*str);
		*str = NULL;
		return (0);
	}
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[256];

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
	{
		*line = NULL;
		return (-1);
	}
	if (read_line(&str[fd], fd) > 0)
		return (build_line(&str[fd], line));
	else
	{
		*line = NULL;
		return (-1);
	}
}
