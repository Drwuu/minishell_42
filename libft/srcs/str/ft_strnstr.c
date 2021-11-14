/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:31:44 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	save;
	int		j;

	i = 0;
	save = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		save = i;
		while (needle[j] && needle[j] == haystack[save] && save < len)
		{
			j++;
			save++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
