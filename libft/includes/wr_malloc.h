/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:39:14 by lwourms           #+#    #+#             */
/*   Updated: 2021/06/29 15:44:10 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WR_MALLOC_H
# define WR_MALLOC_H

void	*wrmalloc(unsigned long size);
int		wrfree(void *ptr);
void	wrdestroy(void);

#endif
