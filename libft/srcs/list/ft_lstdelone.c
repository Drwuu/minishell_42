/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/10/22 16:11:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	del_content(t_list *element)
{
	if (element->type == T_STRING || element->type == T_DICT)
	{
		if (element->content)
		{
			wrfree(element->content);
			element->content = NULL;
		}
	}
}

static void	process_2(t_list **lst, t_list *save)
{
	if (save)
	{
		del_content(save);
		wrfree(save);
		save = NULL;
	}
	else
	{
		del_content(*lst);
		wrfree(*lst);
		*lst = NULL;
	}
}

static void	process(t_list **lst, t_list *save)
{
	if ((*lst)->previous && (*lst)->next)
	{
		(*lst)->previous->next = (*lst)->next;
		(*lst)->next->previous = (*lst)->previous;
	}
	else if ((*lst)->previous)
	{
		save = *lst;
		*lst = (*lst)->previous;
		(*lst)->next = NULL;
	}
	else if ((*lst)->next)
	{
		save = *lst;
		*lst = (*lst)->next;
		(*lst)->previous = NULL;
	}
	process_2(lst, save);
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*save;

	if (!lst)
		return ;
	del_content(*lst);
	save = NULL;
	process(lst, save);
}
