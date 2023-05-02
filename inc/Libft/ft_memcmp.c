/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:06:51 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/13 15:32:51 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*r_s1;
	unsigned char	*r_s2;

	r_s1 = (unsigned char *)s1;
	r_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*r_s1 != *r_s2)
			return (*r_s1 - *r_s2);
		n--;
		r_s1++;
		r_s2++;
	}
	return (0);
}
