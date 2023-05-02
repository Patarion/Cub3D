/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:27:22 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/13 15:47:01 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*r_s1;
	unsigned char	*r_s2;
	size_t			i;

	r_s1 = (unsigned char *) s1;
	r_s2 = (unsigned char *) s2;
	i = 0;
	while (n > 0 && (r_s1[i] != '\0' || r_s2[i] != '\0'))
	{
		if (r_s1[i] != r_s2[i])
			return (r_s1[i] - r_s2[i]);
		n--;
		i++;
	}
	return (0);
}
