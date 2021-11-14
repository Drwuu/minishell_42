/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:39:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/21 14:00:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Get the rest of str from first occurence of to_find */
char	*ft_find_str_in_str(char *str, char *to_find)
{
	int		i;
	int		j;
	int		save;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (to_find[j] && str[i] == to_find[j])
		{
			save = i;
			while (to_find[j] == str[i])
			{
				i++;
				j++;
				if (to_find[j] == '\0')
					return (&str[save]);
			}
			j = 0;
		}
	}
	return (NULL);
}
