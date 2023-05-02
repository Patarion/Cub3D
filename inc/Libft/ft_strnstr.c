/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:27:59 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/13 15:47:26 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*r_h;
	char	*r_n;

	i = 0;
	j = 0;
	r_h = (char *)haystack;
	r_n = (char *)needle;
	if (r_n[j] == '\0')
		return (r_h);
	while (r_h[i] != '\0' && (i + j) <= len)
	{
		while (r_h[i + j] == r_n[j] && r_n[j] != '\0' && (i + j) <= len)
			j++;
		if (r_n[j] == '\0' && (i + j) <= len)
			return (&r_h[i]);
		j = 0;
		i++;
	}
	if (r_h[i + j] == '\0' && r_n[j] == '\0')
		return (&r_h[i]);
	return (0);
}
