/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:30:21 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 20:49:00 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_vec3	ft_vec3_sub(t_vec3 vec_1, t_vec3 vec_2)
{
	t_vec3	new_vec;

	new_vec.x = vec_1.x - vec_2.x;
	new_vec.y = vec_1.y - vec_2.y;
	new_vec.z = vec_1.z - vec_2.z;
	return (new_vec);
}
