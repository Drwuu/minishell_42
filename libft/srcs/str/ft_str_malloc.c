/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:41:49 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/01 13:53:09 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str_malloc(int n, char c)
{
	char			*dest;

	dest = (char *)wrmalloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	dest[n] = 0;
	ft_memset(dest, c, n);
	return (dest);
}
