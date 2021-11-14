/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:33:37 by mhaman            #+#    #+#             */
/*   Updated: 2021/11/10 19:35:13 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strfsnr(char *str, char *search, char *replace)
{
	const size_t	lensearch = ft_strlen(search);
	const size_t	lenreplace = ft_strlen(replace);
	const char		*end = ft_strnstr(str, search, ft_strlen(str));
	char			*ret;

	if (!end)
		return (NULL);
	ret = wrmalloc(ft_strlen(str) + (lenreplace - lensearch) + 1);
	ft_memcpy(ret, str, (ft_strlen(str) - ft_strlen(end)));
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end)), replace, lenreplace);
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end) + lenreplace),
		end + lensearch, ft_strlen(end) - lensearch);
	ret[ft_strlen(str) + (lenreplace - lensearch)] = 0;
	wrfree(str);
	return (ret);
}

char	*ft_strsnr(const char *str, char *search, char *replace)
{
	const size_t	lensearch = ft_strlen(search);
	const size_t	lenreplace = ft_strlen(replace);
	const char		*end = ft_strnstr(str, search, ft_strlen(str));
	char			*ret;

	if (!end)
	{
		return (NULL);
	}
	ret = wrmalloc(ft_strlen(str) + (lenreplace - lensearch) + 1);
	ft_memcpy(ret, str, (ft_strlen(str) - ft_strlen(end)));
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end)), replace, lenreplace);
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end) + lenreplace),
		end + lensearch, ft_strlen(end) - lensearch);
	ret[ft_strlen(str) + (lenreplace - lensearch) - 1] = 0;
	return (ret);
}

char	*ft_strnsnr(char *str, char *search, char *replace, size_t n)
{
	const size_t	lensearch = ft_strlen(search);
	const size_t	lenreplace = ft_strlen(replace);
	const char		*end = ft_strnstr(str + n, search, ft_strlen(str));
	char			*ret;

	if (!end)
		return (NULL);
	ret = wrmalloc(ft_strlen(str) + (lenreplace - lensearch) + 1);
	ft_memcpy(ret, str, (ft_strlen(str) - ft_strlen(end)));
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end)), replace, lenreplace);
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end) + lenreplace),
		end + lensearch, ft_strlen(end) - lensearch);
	ret[ft_strlen(str) + (lenreplace - lensearch)] = 0;
	wrfree(str);
	return (ret);
}

char	*ft_strfnsnr(char *str, char *search, char *replace, size_t n)
{
	const size_t	lensearch = ft_strlen(search);
	const size_t	lenreplace = ft_strlen(replace);
	const char		*end = ft_strnstr(str + n, search, ft_strlen(str));
	char			*ret;

	ret = wrmalloc(ft_strlen(str) + (lenreplace - lensearch) + 1);
	ft_memcpy(ret, str, (ft_strlen(str) - ft_strlen(end)));
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end)), replace, lenreplace);
	ft_memcpy(ret + (ft_strlen(str) - ft_strlen(end) + lenreplace),
		end + lensearch, ft_strlen(end) - lensearch);
	ret[ft_strlen(str) + (lenreplace - lensearch)] = 0;
	return (ret);
}
