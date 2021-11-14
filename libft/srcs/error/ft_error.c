/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 02:04:23 by drwuu             #+#    #+#             */
/*   Updated: 2021/11/09 14:44:40 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void *to_free, void **to_free_2, t_list **lst_nullable, \
const char *msg_error)
{
	if (to_free)
		wrfree(to_free);
	if (to_free_2)
		ft_free_dbl_array(to_free_2, 0);
	if (lst_nullable)
		ft_lstclear(lst_nullable);
	perror(msg_error);
	wrdestroy();
	exit(127);
}
