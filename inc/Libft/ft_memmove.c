/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:07:22 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/14 11:45:40 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*r_dst;
	char	*r_src;
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	r_dst = (char *)dst;
	r_src = (char *)src;
	if (r_src < r_dst)
	{
		while (len--)
		{
			r_dst[len] = r_src[len];
		}
	}
	else
	{
		while (len--)
		{
			r_dst[i] = r_src[i];
			i++;
		}
	}
	return (dst);
}
