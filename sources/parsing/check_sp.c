/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:13:18 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/01 14:14:06 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_sp_redirection(char **str, int i)
{
	if (ft_strnstr(str[0] + i, ">>", 3) != NULL)
	{
		str[0] = ft_strnsnr(str[0], ">>", " >> ", i);
		i += 3;
	}
	else if (ft_strnstr(str[0] + i, "<<", 3) != NULL)
	{
		str[0] = ft_strnsnr(str[0], "<<", " << ", i);
		i += 3;
	}
	else if (ft_strnstr(str[0] + i, ">", 2) != NULL)
	{
		str[0] = ft_strnsnr(str[0], ">", " > ", i);
		i += 2;
	}
	else if (ft_strnstr(str[0] + i, "<", 2) != NULL)
	{
		str[0] = ft_strnsnr(str[0], "<", " < ", i);
		i += 2;
	}
	return (i);
}

int	add_sp_nextcmd(char **str, int i)
{
	if (ft_strnstr(str[0] + i, "|", ft_strlen(str[0]) - i) != NULL)
	{
		str[0] = ft_strnsnr(str[0], "|", " | ", i);
		i += 2;
	}
	return (i);
}

char	*del_sp(t_shell *minis, char *str)
{
	int		i;

	i = 0;
	minis->squote = false;
	minis->dquote = false;
	while (str[i])
	{
		minis->dquote = set_quote(minis->dquote, minis->squote, str[i], '"');
		minis->squote = set_quote(minis->squote, minis->dquote, str[i], '\'');
		while (str[i] == ' ' && str[i + 1] == ' '
			&& !minis->squote && !minis->dquote)
			ft_memcpy(str + i, str + i + 1, ft_strlen(str) - i);
		while (str[i] == '|' && str[i + 1] == ' '
			&& str[i + 2] == 0 && !minis->squote && !minis->dquote)
			ft_memcpy(str + i + 1, str + i + 2, ft_strlen(str) - i);
		i++;
	}
	return (str);
}

char	*check_sp(t_shell *minis, char *str)
{
	int		i;

	i = 0;
	minis->dquote = false;
	minis->squote = false;
	while (str[i])
	{
		minis->dquote = set_quote(minis->dquote, minis->squote, str[i], '"');
		minis->squote = set_quote(minis->squote, minis->dquote, str[i], '\'');
		if (str[i] && (str[i] == '>' || str[i] == '<')
			&& !minis->dquote && !minis->squote)
			i = add_sp_redirection(&str, i);
		if (str[i] && str[i] == '|' && !minis->dquote && !minis->squote)
			i = add_sp_nextcmd(&str, i);
		i++;
	}
	str = del_sp(minis, str);
	return (str);
}
