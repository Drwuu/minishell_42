/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:52:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 04:56:30 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_nb_arg_process(t_shell *minis, size_t *i, size_t *arg)
{
	while (minis->mask[*i] && minis->mask[*i] != EOCP && minis->mask[*i] \
	< OPTION && minis->mask[*i] > RQUOTE && minis->mask[*i] != TODEL)
		*i = *i + 1;
	if (minis->mask[*i] == TODEL && minis->mask[*i + 1] == TODEL)
	{
		*arg = *arg + 1;
		*i = *i + 2;
	}
	if ((minis->mask[*i] >= OPTION && minis->mask[*i] <= RQUOTE) || \
	minis->mask[*i] == TODEL)
	{
		*arg = *arg + 1;
		while ((minis->mask[*i] >= OPTION && minis->mask[*i] <= RQUOTE) || \
		minis->mask[*i] == TODEL)
			*i = *i + 1;
	}
}

int	check_nb_arg(t_shell *minis, size_t *j)
{
	size_t	i;
	size_t	arg;

	i = *j;
	arg = 0;
	if (minis->mask[i] == EOCP)
		i++;
	while (minis->mask[i] && minis->mask[i] != EOCP)
	{
		check_nb_arg_process(minis, &i, &arg);
		if (minis->mask[i] == 0 || minis->mask[i] == EOCP)
		{
			*j = i;
			return (arg);
		}
		i++;
	}
	*j = i;
	return (arg);
}

int	get_cmd_args_nb(char *mask, int from)
{
	int	i;
	int	arg_nb;

	i = from;
	arg_nb = 0;
	while (mask[i])
	{
		if (mask[i] == EOCP)
			break ;
		if (i > 0 && mask[i] == SEP && mask[i + 1] && mask[i + 1] != EOCP && \
		mask[i - 1] && mask[i - 1] != EOCP)
			arg_nb++;
		i++;
	}
	return (arg_nb);
}

char	**create_cmd(char *mask, int from)
{
	char	**cmd;

	cmd = ft_calloc(sizeof(*cmd), get_cmd_args_nb(mask, from) + 1 + 1);
	if (!cmd)
		ft_perror("ft_calloc error");
	return (cmd);
}

bool	is_builtin(t_cmd cmd)
{
	if (!ft_strncmp("echo", cmd.cmd[0], 5) || \
	!ft_strncmp("cd", cmd.cmd[0], 3) || \
	!ft_strncmp("pwd", cmd.cmd[0], 4) || \
	!ft_strncmp("export", cmd.cmd[0], 7) || \
	!ft_strncmp("unset", cmd.cmd[0], 6) || \
	!ft_strncmp("env", cmd.cmd[0], 4) || \
	!ft_strncmp("exit", cmd.cmd[0], 5))
		return (true);
	return (false);
}
