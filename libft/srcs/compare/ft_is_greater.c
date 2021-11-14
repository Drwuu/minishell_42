/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_greater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/24 19:55:24 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_is_greater(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (TRUE);
	else
		return (FALSE);
}
