/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dbl_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:22:19 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/12 20:01:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**ft_free_dbl_array(void **datas, int size_nullable)
{
	int	i;

	i = -1;
	if (!datas)
		return (NULL);
	if (size_nullable)
	{
		while (++i < size_nullable)
			if (datas[i])
				wrfree(datas[i]);
	}
	else
	{
		while (datas[++i])
			if (datas[i])
				wrfree(datas[i]);
	}
	if (datas)
	{
		wrfree(datas);
		datas = NULL;
	}
	return (NULL);
}
