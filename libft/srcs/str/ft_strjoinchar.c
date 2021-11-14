/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:39:24 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/27 19:06:14 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char c)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	str = wrmalloc(sizeof(*str) * (ft_strlen(s1) + 1 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[++i] = c;
	str[++i] = '\0';
	return (str);
}
