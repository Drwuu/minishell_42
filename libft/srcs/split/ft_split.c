/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:28 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:08:54 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	**process(const char *s, const char *sep, char ***split)
{
	int	new_word;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_word = 0;
	while (s[i])
	{
		if (!is_sep(s, sep, i))
		{
			if (!new_word)
			{
				(*split)[j] = build_str(s, sep, i);
				if (!(*split)[j++])
					return (ft_free_dbl_array((void **)(*split), 0));
				new_word = 1;
			}
		}
		else
			new_word = 0;
		i++;
	}
	(*split)[j] = 0;
	return ((void **)0);
}

char	**ft_split(const char *s, const char *sep)
{
	char	**split;

	if (!s)
		return (NULL);
	split = wrmalloc(sizeof(*split) * (count_str(s, sep) + 1));
	if (!split)
		return (NULL);
	process(s, sep, &split);
	return (split);
}
