/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:10:48 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/25 15:38:53 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char
			*src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char
		*src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (dstsize >= 1)
	{
		while (dstsize > 1 && *src != '\0')
		{
			*dst = *src;
			dstsize--;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (i);
}
