/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:35:04 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/03 09:33:07 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_malloc_value(char *env)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	j = i + 1;
	i = ft_strlen(env) - j;
	value = wrmalloc(sizeof(char) * i + 1);
	i = 0;
	while (env[j])
	{
		value[i] = env[j];
		i++;
		j++;
	}
	value[i] = '\0';
	return (value);
}

static char	*ft_malloc_name(char *env)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	name = wrmalloc(sizeof(char) * i + 1);
	while (i > j)
	{
		name[j] = env[j];
		j++;
	}
	name[j] = '\0';
	return (name);
}

static t_env	*ft_creat_env(char *env)
{
	t_env	*menv;

	menv = wrmalloc(sizeof(t_env));
	menv->name = NULL;
	menv->value = NULL;
	menv->name = ft_malloc_name(env);
	menv->value = ft_malloc_value(env);
	menv->next = NULL;
	return (menv);
}

void	ft_add_env(t_env *menv, char *env)
{
	t_env	*tmp;

	tmp = wrmalloc(sizeof(t_env));
	while (menv->next)
		menv = menv->next;
	tmp->name = NULL;
	tmp->value = NULL;
	tmp->name = ft_malloc_name(env);
	tmp->value = ft_malloc_value(env);
	tmp->next = NULL;
	menv->next = tmp;
}

t_env	*ft_set_env(char **env)
{
	int		i;
	t_env	*menv;

	i = 0;
	menv = NULL;
	if (env)
	{
		while (env[i])
		{
			if (menv == NULL)
				menv = ft_creat_env(env[i]);
			else
				ft_add_env(menv, env[i]);
			i++;
		}
	}
	return (menv);
}
