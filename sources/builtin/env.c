/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:15:27 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/05 12:42:58 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *shell, char **cmd __attribute__((unused)))
{
	const t_env	*env = shell->env;

	while (env)
	{
		ft_putstr_fd(env->name, 1);
		write(1, "=", 1);
		ft_putstr_fd(env->value, 1);
		write(1, "\n", 1);
		env = env->next;
	}
	return (0);
}
