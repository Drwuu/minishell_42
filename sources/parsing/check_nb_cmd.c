/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:59:13 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/01 16:22:50 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	set_quote(bool quote, bool cond, char c, char t)
{
	if (c == t && cond == false)
	{
		if (quote == false)
			return (1);
		else
			return (0);
	}
	return (quote);
}

int	syntax_error(char *error, char c)
{
	const char	str[47] = "minishell$ syntax error near unexpected token '";

	write(2, str, 47);
	if (c != 0)
		write(2, &c, 1);
	else
		write(2, error, ft_strlen(error));
	write(2, "' \n", 4);
	return (-1);
}

size_t	check_nb_cmd(t_shell *minis, const char *line)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = 1;
	minis->squote = false;
	minis->dquote = false;
	while (line[i])
	{
		minis->squote = set_quote(minis->squote, minis->dquote, line[i], '\'');
		minis->dquote = set_quote(minis->dquote, minis->squote, line[i], '"');
		if (line[i] == '|' && minis->squote == false && minis->dquote == false)
			nb++;
		i++;
	}
	return (nb);
}
