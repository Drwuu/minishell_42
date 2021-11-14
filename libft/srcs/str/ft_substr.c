/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:42:40 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:11:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_real_len(char const *s, size_t len, unsigned int start)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = start;
	while (s[i++] && j < (unsigned int)len)
		j++;
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if ((size_t)start >= ft_strlen(s))
	{
		str = wrmalloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = wrmalloc(sizeof(*str) * (find_real_len(s, len, start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = start;
	while (j < start + (unsigned int)len && s[j])
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
