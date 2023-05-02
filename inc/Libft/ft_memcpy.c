/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:07:03 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/14 11:45:42 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*r_src;
	char	*r_dst;

	if (!dst && !src)
		return (0);
	r_src = (char *)src;
	r_dst = (char *)dst;
	while (n > 0)
	{
		*r_dst = *r_src;
		r_dst++;
		r_src++;
		n--;
	}
	return (dst);
}
