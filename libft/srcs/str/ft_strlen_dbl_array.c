/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_dbl_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:19:15 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/02 13:16:28 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Get lenght of the first dimension of an array.
	double_array need to be NULL terminated
*/
int	ft_strlen_dbl_array(char **double_array)
{
	int	i;

	i = 0;
	if (!double_array)
		return (0);
	while (double_array[i])
		i++;
	return (i);
}
