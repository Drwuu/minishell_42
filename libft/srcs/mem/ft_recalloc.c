/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:05:56 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/11 14:08:21 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_recalloc(char *old, size_t size, size_t count)
{
	char	*tab;
	size_t	i;

	i = -1;
	tab = wrmalloc(size * (ft_strlen(old) + count));
	if (!tab)
		return (NULL);
	while (++i < (ft_strlen(old) + count) * size)
		tab[i] = 0;
	i = -1;
	while (old[++i])
		tab[i] = old[i];
	wrfree(old);
	return (tab);
}
