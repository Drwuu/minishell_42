/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaman <mhaman@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:56:07 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/11 17:12:35 by mhaman           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mask_todel_sep(t_shell *minis, char *str, size_t i)
{
	if (str[i] == '\'' && minis->mask[i] == '2')
		minis->mask[i] = TODEL;
	if (str[i] == '"' && minis->mask[i] == '1')
		minis->mask[i] = TODEL;
	if (str[i] == '|' && minis->mask[i] == '0')
		minis->mask[i] = EOCP;
	if (str[i] == ' ' && minis->mask[i] == '0')
		minis->mask[i] = SEP;
}

void	mask_initialization(t_shell *minis, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		minis->squote = set_quote(minis->squote, minis->dquote, '\'', str[i]);
		minis->dquote = set_quote(minis->dquote, minis->squote, '"', str[i]);
		if (minis->squote || (str[i] == '\'' && minis->mask[i - 1] == '2'))
			minis->mask[i] = RQUOTE;
		if (minis->dquote || (str[i] == '"' && minis->mask[i - 1] == '1'))
			minis->mask[i] = QUOTE;
		i++;
	}
}

void	mask_env_var(t_shell *minis, char *str, size_t *j)
{
	size_t	i;

	i = *j;
	if (str[i] == '$' && minis->mask[i] != '2' && str[i + 1] == '?')
	{
		minis->mask[i] = DOLINT;
		minis->mask[i + 1] = DOLINT;
		i += 2;
	}
	if (str[i] == '$' && minis->mask[i] != '2'
		&& (ft_isalpha(str[i + 1]) == 1 || str[i + 1] == '_'))
	{
		minis->mask[i] = MVENV;
		while (str[++i] == '_' || ft_isalpha(str[i]) == 1)
			minis->mask[i] = MVENV;
		i--;
	}
	*j = i;
}

void	mask_redir(t_shell *minis, char *str, size_t *j)
{
	size_t	i;

	i = *j;
	if (str[i] == '>' && str[i + 1] == '>' && minis->mask[i] == '0'
		&& minis->mask[i + 1] == '0')
	{
		minis->mask[i] = SSREDIR;
		minis->mask[i + 1] = SSREDIR;
		i += 1;
	}
	if (str[i] == '<' && str[i + 1] == '<' && minis->mask[i] == '0'
		&& minis->mask[i + 1] == '0')
	{
		minis->mask[i] = DREDIR;
		minis->mask[i + 1] = DREDIR;
		i += 1;
	}
	if (str[i] == '>' && str[i + 1] != '>' && minis->mask[i] == '0')
		minis->mask[i] = SREDIR;
	if (str[i] == '<' && str[i + 1] != '>' && minis->mask[i] == '0')
		minis->mask[i] = FREDIR;
	*j = i;
}

void	create_mask(t_shell *minis, char *str)
{
	size_t	i;

	i = 0;
	minis->mask = ft_str_malloc(ft_strlen(minis->line), '0');
	minis->squote = false;
	minis->dquote = false;
	mask_initialization(minis, str);
	while (i < ft_strlen(str) && str[i])
	{
		mask_env_var(minis, str, &i);
		mask_todel_sep(minis, str, i);
		mask_redir(minis, str, &i);
		i++;
	}
}
