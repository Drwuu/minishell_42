/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:50:18 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/28 13:07:07 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_printf_color(t_pf_color color)
{
	if (color == RED)
		return ("\x1B[31m");
	else if (color == GREEN)
		return ("\x1B[32m");
	else if (color == YELLOW)
		return ("\x1B[33m");
	else if (color == BLUE)
		return ("\x1B[34m");
	else if (color == CYAN)
		return ("\x1B[36m");
	else if (color == MAGENTA)
		return ("\x1B[35m");
	else if (color == BLACK)
		return ("\x1B[30m");
	else if (color == RESET)
		return ("\x1B[0m");
	return (NULL);
}
