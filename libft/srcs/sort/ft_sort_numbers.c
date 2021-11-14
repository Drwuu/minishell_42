/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:04:23 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/25 20:57:50 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_sort_array_ascending(int **pt_array, int size)
{
	int	temp;
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if ((*pt_array)[i + 1] < (*pt_array)[i])
		{
			temp = (*pt_array)[i];
			(*pt_array)[i] = (*pt_array)[i + 1];
			(*pt_array)[i + 1] = temp;
			i = -1;
		}
	}
}

void	ft_sort_array_descending(int **pt_array, int size)
{
	int	temp;
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if ((*pt_array)[i + 1] > (*pt_array)[i])
		{
			temp = (*pt_array)[i];
			(*pt_array)[i] = (*pt_array)[i + 1];
			(*pt_array)[i + 1] = temp;
			i = -1;
		}
	}
}
