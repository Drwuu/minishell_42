/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_at_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drwuu <drwuu@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:37:56 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/25 04:29:35 by drwuu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_at_fd(const char *s, int start, int end, int fd)
{
	if (!s)
		return ;
	while (s[start] && start <= end)
	{
		write(fd, &s[start], 1);
		start++;
	}
}
