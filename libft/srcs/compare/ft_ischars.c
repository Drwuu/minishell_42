/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:33:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/27 10:16:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Check if str contains one of the char in chars
 */
int	ft_ischars(const char *str, const char *chars)
{
	const char	*save;

	save = chars;
	if (!str || !chars)
		return (-1);
	while (*str)
	{
		while (*chars)
			if (*chars++ == *str)
				return (TRUE);
		chars = save;
		str++;
	}
	return (FALSE);
}
