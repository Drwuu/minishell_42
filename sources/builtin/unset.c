/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:33:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/12 19:50:46 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remove_env(t_shell *shell, t_env *env)
{
	t_env	*tmp;
	t_env	*ptr;

	ptr = shell->env;
	tmp = env->next;
	while (ptr != env)
	{
		if (ptr->next == env)
		{
			ptr->next = tmp;
			break ;
		}
		ptr = ptr->next;
	}
	wrfree(env->name);
	wrfree(env->value);
	wrfree(env);
	return (0);
}

int	builtin_unset(t_shell *shell, char **cmd)
{
	size_t	i;
	t_env	*ptr;

	ptr = shell->env;
	i = 0;
	if (cmd[1] == NULL)
		return (0);
	while (cmd[++i])
	{
		while (ptr)
		{
			if (ft_strncmp(cmd[i], ptr->name, ft_strlen(cmd[i]) + 1) == 0)
			{
				remove_env(shell, ptr);
				break ;
			}
			ptr = ptr->next;
		}
		ptr = shell->env;
	}
	update_env(shell);
	return (0);
}
