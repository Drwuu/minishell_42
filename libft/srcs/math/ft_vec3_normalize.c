/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:30:21 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:12:26 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_vec3	ft_vec3_normalize(t_vec3 vector)
{
	float	dist;

	dist = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
	dist = sqrtf(dist);
	vector.x /= dist;
	vector.y /= dist;
	vector.z /= dist;
	return (vector);
}
