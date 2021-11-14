/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:33:01 by lwourms           #+#    #+#             */
/*   Updated: 2021/10/22 16:05:47 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_n_len(unsigned long long n, int b_size)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= b_size;
	}
	return (len);
}

static void	convert_process(unsigned long long n, char *result, int len, \
const char *base)
{
	result[len - 1] = base[n % ft_strlen(base)];
	if (n >= (unsigned long long)ft_strlen(base))
		convert_process(n / ft_strlen(base), result, --len, base);
}

char	*ft_itoa_base(const char *base, unsigned long long n)
{
	char	*result;
	int		n_len;
	int		b_size;

	b_size = ft_strlen(base);
	n_len = find_n_len(n, b_size);
	result = wrmalloc(sizeof(*result) * (n_len + 1));
	if (!result)
		return (NULL);
	convert_process(n, result, n_len, base);
	result[n_len] = '\0';
	return (result);
}
