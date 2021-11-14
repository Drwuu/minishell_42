/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_smaller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 18:57:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_is_smaller(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (TRUE);
	else
		return (FALSE);
}
