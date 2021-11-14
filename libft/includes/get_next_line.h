/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:05:04 by ludwuu            #+#    #+#             */
/*   Updated: 2021/10/22 16:03:33 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(int fd, char **line);
int		find_newline(char *str);
int		copy_line(const char *buf, char **str);
int		free_str_error(char *str, char *buf);

#endif
