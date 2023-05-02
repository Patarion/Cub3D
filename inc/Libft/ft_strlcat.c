/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:41 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/13 15:45:44 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < dstsize)
		i++;
	if (dstsize <= i)
		return (dstsize + (ft_strlen(src)));
	while ((j + i) < (dstsize - 1) && src[j] != '\0' && dstsize > 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (size);
}
