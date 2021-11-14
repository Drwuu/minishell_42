/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:13:34 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:11:21 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*malloc_error(char *str)
{
	str = wrmalloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	return (str);
}

static int	process(char **str, char const *s1, int start, int end)
{
	int	i;

	*str = wrmalloc(sizeof(**str) * (end - start + 2));
	if (!*str)
		return (0);
	i = 0;
	while (start <= end)
		(*str)[i++] = (char)s1[start++];
	(*str)[i] = '\0';
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && is_set(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_set(set, s1[end]) && end > 0)
		end--;
	if (end < start)
	{
		str = NULL;
		return (malloc_error(str));
	}
	if (!process(&str, s1, start, end))
		return (NULL);
	return (str);
}
