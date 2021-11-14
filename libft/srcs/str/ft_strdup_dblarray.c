/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_dblarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:59:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/30 14:24:45 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_dblarray(const char **dbl_array, int size)
{
	char	**new_array;
	int		i;
	int		j;

	i = -1;
	new_array = wrmalloc((sizeof(*new_array) * (size + 1)));
	if (!new_array)
		ft_perror("ft_strdup_dblarray error");
	while (++i < size)
	{
		j = -1;
		new_array[i] = wrmalloc((sizeof(**new_array) * \
		(ft_strlen(dbl_array[i]) + 1)));
		if (!new_array[i])
			ft_perror("ft_strdup_dblarray error");
		while (dbl_array[i][++j])
			new_array[i][j] = dbl_array[i][j];
		new_array[i][j] = '\0';
	}
	new_array[i] = NULL;
	return (new_array);
}
