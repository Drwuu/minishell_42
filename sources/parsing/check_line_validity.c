/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:07:51 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/01 13:46:58 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_validity(t_shell *minis, const char *line)
{
	size_t	i;

	i = 0;
	minis->squote = false;
	minis->dquote = false;
	while (line[i])
	{
		minis->dquote = set_quote(minis->dquote, minis->squote, line[i], '"');
		minis->squote = set_quote(minis->squote, minis->dquote, line[i], '\'');
		i++;
	}
	if (minis->squote == true || minis->dquote == true)
	{
		write(1, "minishell> quote Should be close\n", 34);
		return (-1);
	}
	return (0);
}

int	check_redirection_syntax(const char *s, size_t *j)
{
	size_t	i;

	i = *j;
	if (ft_strnstr(s + i, ">>>", 3) != NULL)
		return (syntax_error(NULL, '>'));
	if (ft_strnstr(s + i, "<<<", 3) != NULL
		|| (s[i] == '>' && s[i + 1] == '<'))
		return (syntax_error(NULL, '<'));
	if ((s[i] == '<' || s[i] == '>') && (s[i + 1] == '\0' || s[i + 1] == '|'))
		return (syntax_error("newline", 0));
	i++;
	if (s[i] && s[i] == ' ')
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] == '>' || s[i] == '<' || s[i] == '\0' || s[i] == '|')
		{
			if (s[i] == '>' || s[i] == '<')
				return (syntax_error(NULL, s[i]));
			return (syntax_error("newline", 0));
		}
	}
	*j = i;
	return (0);
}

int	check_redirection_validity(t_shell *minis, const char *line)
{
	size_t	i;

	i = 0;
	minis->squote = false;
	minis->dquote = false;
	while (line[i])
	{
		minis->squote = set_quote(minis->squote, minis->dquote, line[i], '\'');
		minis->dquote = set_quote(minis->dquote, minis->squote, line[i], '"');
		if ((line[i] == '<' || line[i] == '>')
			&& !minis->squote && !minis->dquote)
		{
			if (check_redirection_syntax(line, &i) != 0)
				return (-1);
		}
		else
			i++;
	}
	return (0);
}

int	check_nextcmd_validity(t_shell *minis, const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		minis->squote = set_quote(minis->squote, minis->dquote, line[i], '\'');
		minis->dquote = set_quote(minis->dquote, minis->squote, line[i], '"');
		if (line[0] == '|')
			return (syntax_error(NULL, line[0]));
		if (line[i] && line[i] == '|' && !minis->squote && !minis->dquote)
		{
			i++;
			if (line[i] == ' ')
				while (line[i] == ' ')
					i++;
			if (line[i] == '|' || line[i] == 0)
				return (syntax_error(NULL, '|'));
		}
		else
			i++;
	}
	return (0);
}

int	check_line_valitidy(t_shell *minis, const char *line)
{
	if (check_quote_validity(minis, line) == -1)
		return (-1);
	if (check_redirection_validity(minis, line) == -1)
		return (-1);
	if (check_nextcmd_validity(minis, line) == -1)
		return (-1);
	return (0);
}
