/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_wfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:39:24 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/09 15:14:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_wfree(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = wrmalloc((sizeof(*str) * ((ft_strlen(s1) + \
		ft_strlen(s2)) + 1)));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	wrfree(s1);
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	wrfree(s2);
	str[j] = '\0';
	return (str);
}
