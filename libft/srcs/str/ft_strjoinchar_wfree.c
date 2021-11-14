/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar_wfree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:39:24 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/30 14:22:20 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar_wfree(char *s1, char c)
{
	char	*str;
	int		i;

	str = NULL;
	if (!s1)
		ft_perror("ft_strjoinchar_wfree error");
	str = wrmalloc(sizeof(*str) * (ft_strlen(s1) + 1 + 1));
	if (!str)
		ft_perror("ft_strjoinchar_wfree error");
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = c;
	str[++i] = '\0';
	wrfree(s1);
	return (str);
}
