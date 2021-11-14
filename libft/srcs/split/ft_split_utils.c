/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:28 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:08:56 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_sep(const char *str, const char *sep, int i)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		if (str[i] == sep[j])
			return (1);
		j++;
	}
	return (0);
}

int	count_str(const char *str, const char *sep)
{
	int	i;
	int	words;
	int	new_word;

	i = 0;
	words = 0;
	new_word = 0;
	while (str[i])
	{
		if (!is_sep(str, sep, i))
		{
			if (!new_word)
			{
				new_word = 1;
				words++;
			}
		}
		else
			new_word = 0;
		i++;
	}
	return (words);
}

int	char_nbr(const char *str, const char *sep, int i)
{
	int	char_nbr;

	char_nbr = 0;
	while (str[i])
	{
		if (!is_sep(str, sep, i))
			char_nbr++;
		else
			return (char_nbr);
		i++;
	}
	return (char_nbr);
}

char	*build_str(const char *str, const char *sep, int i)
{
	char	*build_str;
	int		size;
	int		j;
	int		k;

	size = char_nbr(str, sep, i);
	build_str = wrmalloc(sizeof(*build_str) * (size + 1));
	if (!build_str)
		return (NULL);
	j = 0;
	k = 0;
	while (j < size)
	{
		build_str[k] = str[i++];
		k++;
		j++;
	}
	build_str[k] = '\0';
	return (build_str);
}
