/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:45:26 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/13 03:29:55 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdel(char *str, int index)
{
	char	*end;

	end = str + index + 1;
	str[index] = 0;
	ft_strlcat(str, end, ft_strlen(str) + ft_strlen(end) + 1);
	return (str);
}
