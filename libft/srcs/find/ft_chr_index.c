/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:22:48 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_chr_index(const char *str, const char c, int i)
{
	if (!str || !c || i < 0)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
