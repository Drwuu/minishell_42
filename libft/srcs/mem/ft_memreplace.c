/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:30:49 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/09 19:09:07 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memreplace(void *b, int c, int from, int to)
{
	while (from < to)
	{
		((unsigned char *)b)[from] = c;
		from++;
	}
	return (b);
}
