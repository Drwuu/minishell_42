/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 07:46:11 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/12 22:20:03 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_env(t_env *env, char *cmd)
{
	size_t		i;
	const char	*name = cmd;
	char		*value;

	i = 0;
	while (cmd[i] && cmd[i] != '=')
		i++;
	if (cmd[i] == '\0')
		return (-1);
	cmd[i] = 0;
	value = cmd + (i + 1);
	while (env)
	{
		if (ft_strncmp(name, env->name, ft_strlen(name) + 1) == 0)
		{
			wrfree(env->value);
			env->value = ft_strdup(value);
			return (1);
		}
		env = env->next;
	}
	cmd[i] = '=';
	return (0);
}

int	ft_valid_env(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i] != '=')
	{
		if (ft_isalpha(cmd[i]) != 1 && cmd[i] != '_')
		{
			ft_putstr_fd("minishell : export: ", 1);
			ft_putstr_fd(cmd, 1);
			ft_putstr_fd(": not a valid identifier\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	builtin_export(t_shell *shell, char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[++i])
	{
		if (ft_valid_env(cmd[i]) == 0)
			if (ft_change_env(shell->env, cmd[i]) == 0)
				ft_add_env(shell->env, cmd[i]);
	}
	return (0);
}
