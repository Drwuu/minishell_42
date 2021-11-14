/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:21:17 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 20:34:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_UTILS_H
# define SPLIT_UTILS_H

int		is_sep(const char *str, const char *sep, int i);
int		count_str(const char *str, const char *sep);
int		char_nbr(const char *str, const char *sep, int i);
char	*build_str(const char *str, const char *sep, int i);

#endif
