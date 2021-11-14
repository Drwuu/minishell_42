/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:11:25 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/13 04:38:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_dol_int(t_shell *minis, size_t i)
{
	char	*found;
	char	*replace;

	found = ft_substr(minis->line, i - 1, 2);
	replace = ft_itoa(g_status);
	minis->line = ft_strnsnr(minis->line, found, replace, i - 1);
	minis->mask = ft_strnsnr(minis->mask, ft_str_malloc(ft_strlen(found), \
	DOLINT), ft_str_malloc(ft_strlen(replace), OPTION), i - 1);
	return (0);
}

void	calc_heredoc_process(t_shell *minis, size_t *i, char ***tmp, size_t *j)
{
	while (minis->mask[*i])
	{
		if (minis->mask[*i] == DREDIR)
		{
			*i = *i + 3;
			while (minis->mask[*i + *j] && minis->mask[*i + *j] != SEP)
			{
				if (minis->mask[*i + *j] == TODEL)
				{
					minis->line = ft_strdel(minis->line, *i + *j);
					minis->mask = ft_strdel(minis->mask, *i + *j);
					*j = *j - 1;
				}
				*j = *j + 1;
			}
			**tmp = ft_substr(minis->line, *i, *j);
			*tmp = *tmp + 1;
			*i = *i + *j - 1;
			*j = 0;
		}
		*i = *i + 1;
	}
}

void	calc_heredoc(t_shell *minis)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	**tmp;

	i = 0;
	j = 0;
	str = NULL;
	while (minis->mask[i])
	{
		if (minis->mask[i] == DREDIR && minis->mask[++i] == DREDIR)
			j++;
		i++;
	}
	minis->heredoc = ft_calloc(sizeof(char *), j + 1);
	tmp = minis->heredoc;
	str = *tmp;
	j = 0;
	i = 0;
	calc_heredoc_process(minis, &i, &tmp, &j);
	*tmp = str;
}

void	create_mask_post_env(t_shell *minis)
{
	size_t	i;

	i = 0;
	while (minis->mask[i] && minis->mask[i] != MVENV)
		i++;
	while (minis->mask[i] && minis->mask[i] == MVENV)
	{
		if (minis->line[i] == ' ' && minis->line[i + 1] == ' ')
		{
			minis->mask[i] = SEP;
			i++;
			while (minis->mask[i] == MVENV && minis->line[i] == ' ')
			{
				minis->line = ft_strdel(minis->line, i);
				minis->mask = ft_strdel(minis->mask, i);
			}
			minis->mask[i] = OPTION;
		}
		else if (minis->line[i] == ' ')
			minis->mask[i] = SEP;
		else
			minis->mask[i] = OPTION;
		i++;
	}
}
