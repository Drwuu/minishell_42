/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:08:11 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/12 22:22:17 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	changepwd(t_shell *shell, char *pwd)
{
	t_env	*ptr;
	char	*str;

	str = ft_strdup(pwd);
	ptr = shell->env;
	while (ptr)
	{
		if (ft_strncmp("PWD", ptr->name, ft_strlen("PWD") + 1) == 0)
		{
			wrfree(ptr->value);
			ptr->value = str;
		}
		ptr = ptr->next;
	}
	free(pwd);
}

char	*getenv_name(t_shell *shell, char *name)
{
	t_env	*ptr;

	ptr = shell->env;
	while (ptr)
	{
		if (ft_strncmp(name, ptr->name, ft_strlen(name) + 1) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

/* Si Rien HOME Si pas '/' Absolute sinon $PWD */

int	builtin_cd(t_shell *shell, char **cmd)
{
	char	*home;
	int		ret;

	home = getenv_name(shell, "HOME");
	if (cmd[1] == NULL)
	{
		if (home == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 1);
			return (1);
		}
		ret = chdir(home);
		cmd[1] = home;
	}
	else
		ret = chdir(cmd[1]);
	changepwd(shell, getcwd(NULL, 0));
	if (ret == -1)
	{
		perror(cmd[1]);
		return (1);
	}
	return (0);
}
