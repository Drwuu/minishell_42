/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/29 17:11:05 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Check if str contains the char c
 */
int	ft_ischar(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}
