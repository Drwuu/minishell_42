/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:37:25 by lwourms           #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (long)n * -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	nbr %= 10;
	c = nbr + '0';
	write(fd, &c, 1);
}
