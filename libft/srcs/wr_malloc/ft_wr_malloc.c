/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wr_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:34:17 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/12 22:16:41 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**wrgetter(void)
{
	static t_list	*wrm;

	return (&wrm);
}

void	*wrmalloc(unsigned long size)
{
	char	*buffer;
	t_list	*new_elem;

	buffer = malloc(size);
	if (!buffer)
	{
		wrdestroy();
		return (NULL);
	}
	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		wrdestroy();
		return (NULL);
	}
	new_elem->content = buffer;
	new_elem->next = NULL;
	ft_lstadd_back(wrgetter(), new_elem);
	return (buffer);
}

static void	wr_free_process(t_list	*current, void *to_free)
{
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	if (current)
	{
		free(current);
		current = NULL;
	}
}

int	wrfree(void *to_free)
{
	t_list	**wrstart;
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	wrstart = wrgetter();
	prev = NULL;
	current = *wrstart;
	while (current)
	{
		next = current->next;
		if (current->content == to_free)
		{
			wr_free_process(current, to_free);
			if (prev)
				prev->next = next;
			else
				*wrstart = next;
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

void	wrdestroy(void)
{
	t_list	*current;
	t_list	*next;
	t_list	**wrstart;

	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		if (current->content)
		{
			free(current->content);
			current->content = NULL;
		}
		if (current)
		{
			free(current);
			current = NULL;
		}
		current = next;
	}
	*wrstart = NULL;
}
