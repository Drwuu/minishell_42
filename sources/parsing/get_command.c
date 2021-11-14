/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:52:23 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/13 05:05:10 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct args
{
	size_t	i;
	size_t	len;
	size_t	arg;
	size_t	k;
}	t_args;

void	fill_arg_process(t_shell *minis, t_args *args, size_t cmd)
{
	while (minis->mask[args->i + args->len] >= OPTION && \
	minis->mask[args->i + args->len] <= RQUOTE)
	{
		args->len = args->len + 1;
		if (minis->mask[args->i + args->len] == TODEL)
		{
			minis->line = ft_strdel(minis->line, args->i + args->len);
			minis->mask = ft_strdel(minis->mask, args->i + args->len);
			args->len = args->len - 1;
		}
	}
	minis->cmd[cmd].cmd[args->k++] = \
	ft_substr(minis->line, args->i, args->len);
	args->i += args->len;
	args->len = 0;
}

void	fill_arg(t_shell *minis, size_t *j, size_t cmd)
{
	t_args	args;

	args.i = *j;
	args.k = 0;
	args.len = 0;
	args.arg = 0;
	args.arg = check_nb_arg(minis, j);
	while (args.i < *j)
	{
		if (minis->mask[args.i] == TODEL && minis->mask[args.i + 1] == TODEL)
		{
			minis->cmd[cmd].cmd[args.k++] = ft_strdup("");
			args.i += 2;
		}
		else if (minis->mask[args.i] >= OPTION && minis->mask[args.i] <= RQUOTE)
			fill_arg_process(minis, &args, cmd);
		args.i++;
	}
	*j = args.i;
	minis->cmd[cmd].cmd[args.k] = NULL;
}

int	split_command(t_shell *minis)
{
	size_t	i;
	size_t	cmd;

	i = 0;
	cmd = 0;
	while (cmd < minis->nbcmd)
		minis->cmd[cmd++].cmd = ft_calloc(sizeof(char *), \
		check_nb_arg(minis, &i) + 1);
	i = 0;
	cmd = 0;
	while (cmd < minis->nbcmd)
	{
		fill_arg(minis, &i, cmd);
		cmd++;
	}
	if (minis->cmd[0].cmd[0] == NULL)
		return (-1);
	if (minis->cmd[0].cmd[0] != NULL && is_builtin(minis->cmd[0]))
		minis->cmd[0].is_builtin = TRUE;
	return (0);
}
