/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:06:36 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/13 15:23:23 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*r_s;
	char	r_c;

	r_s = (char *)s;
	r_c = (char)c;
	while (n > 0)
	{
		if (*r_s == r_c)
			return (r_s);
		r_s++;
		n--;
	}
	return (0);
}
