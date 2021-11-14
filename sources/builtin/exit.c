/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:00:58 by lwourms           #+#    #+#             */
/*   Updated: 2021/11/10 19:43:39 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(t_shell *shell __attribute__((unused)), char **cmd)
{
	if (cmd[1] == NULL)
		exit(EXIT_SUCCESS);
	exit(ft_atoi(cmd[1]));
}
