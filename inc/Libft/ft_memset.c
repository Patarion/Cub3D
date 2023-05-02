/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:50:31 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/27 14:19:53 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int f, size_t len);

void	*ft_memset(void *str, int f, size_t len)
{
	unsigned char	*r_str;

	r_str = (unsigned char *)str;
	while (len--)
	{
		*r_str = (unsigned char)f;
		r_str++;
	}
	return (str);
}
