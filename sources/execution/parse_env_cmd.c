/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:49:16 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 03:18:39 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_binary(char *cmd, char **env_parsed)
{
	char	*tmp;
	char	*cmd_path;
	int		i;

	i = -1;
	cmd_path = NULL;
	tmp = NULL;
	if (!env_parsed)
		return (NULL);
	while (env_parsed[++i])
	{
		tmp = ft_strjoin(env_parsed[i], "/");
		if (!tmp)
			ft_error(cmd_path, (void **)env_parsed, NULL, "tmp join failed");
		cmd_path = ft_strjoin(tmp, cmd);
		if (!cmd_path)
			ft_error(tmp, (void **)env_parsed, NULL, "cmd_path join failed");
		wrfree(tmp);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		wrfree(cmd_path);
	}
	return (NULL);
}
