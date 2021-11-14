/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:51:53 by drwuu             #+#    #+#             */
/*   Updated: 2021/06/08 17:25:10 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	prepare(void *(*f)(void *), t_list **lst, t_list **new_list, \
t_list **first_elem)
{
	if (!*lst)
		return (0);
	*new_list = ft_lstnew(f((*lst)->content), (*lst)->type);
	if (!*new_list)
		return (0);
	*first_elem = *new_list;
	(*lst)->previous = *lst;
	*lst = (*lst)->next;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*first_elem;

	if (!prepare(f, &lst, &new_list, &first_elem))
		return (NULL);
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content), lst->type);
		if (!new_list->next)
		{
			ft_lstclear(&first_elem);
			return (NULL);
		}
		lst->previous = lst;
		lst = lst->next;
		new_list->previous = new_list;
		new_list = new_list->next;
	}
	new_list->next = NULL;
	return (first_elem);
}
