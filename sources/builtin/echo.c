/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:49:37 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/12 20:10:45 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(t_shell *shell __attribute__((unused)), char **cmd)
{
	t_bool	option;
	int		i;

	i = 0;
	option = FALSE;
	if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0)
	{
		option = TRUE;
		i++;
	}
	while (cmd[++i])
	{
		if (i != 1 + (int)option)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(cmd[i], 1);
	}
	if (!option)
		ft_putchar_fd('\n', 1);
	return (0);
}
