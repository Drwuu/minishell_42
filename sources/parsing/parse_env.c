/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:11:25 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/13 03:59:16 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *found, t_env *env, size_t len)
{
	while (env)
	{
		if (ft_strncmp(found, env->name, len + 1) == 0)
			return (env->value);
		else
			env = env->next;
	}
	return (NULL);
}

void	replace_env_process(t_shell *minis, size_t i, size_t j, char *found)
{
	minis->line = ft_strnsnr(minis->line, found, "", i - j - 1);
	minis->mask = ft_strfnsnr(minis->mask, \
	ft_str_malloc(ft_strlen(found), 'a'), ft_strdup(""), i - j - 1);
}

int	replace_env(t_shell *minis, size_t i, size_t j)
{
	char	*found;
	char	*replace;

	if (minis->mask[i] == DOLINT)
		return (replace_dol_int(minis, i));
	found = ft_substr(minis->line, i - j - 1, j + 1);
	replace = NULL;
	if (find_env(found + 1, minis->env, ft_strlen(found) - 1) != NULL)
	{
		replace = find_env(found + 1, minis->env, ft_strlen(found) - 1);
		minis->line = ft_strnsnr(minis->line, found, replace, i - j - 1);
		minis->mask = ft_strfnsnr(minis->mask, \
			ft_str_malloc(ft_strlen(found), 'a'), \
			ft_str_malloc(ft_strlen(replace), MVENV), i - j - 1);
	}
	else
		replace_env_process(minis, i, j, found);
	if (minis->line[i - j - 1] == 0)
	{
		minis->line = NULL;
		minis->mask = NULL;
		return (-1);
	}
	return (0);
}

int	reverse_env(t_shell *minis)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (minis->line[i])
	{
		if (minis->line[i] == '$'
			&& (minis->mask[i] == MVENV || minis->mask[i] == DOLINT))
		{
			i++;
			while (ft_isalpha(minis->line[i]) == 1 || minis->line[i] == '_')
			{
				i++;
				j++;
			}
			if (replace_env(minis, i, j) == -1)
				return (-1);
			i = 0;
			j = 0;
		}
		i++;
	}
	return (0);
}

void	update_env(t_shell *minis)
{
	t_env	*ptr;
	size_t	i;

	i = 0;
	ptr = minis->env;
	if (minis->envp != NULL)
		wrfree(minis->envp);
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	minis->envp = wrmalloc(sizeof(char *) * (i + 1));
	ptr = minis->env;
	i = 0;
	while (ptr)
	{
		minis->envp[i] = ft_strjoin_with_sep(ft_strdup(ptr->name), \
		ptr->value, '=');
		ptr = ptr->next;
		i++;
	}
	minis->envp[i] = NULL;
}
