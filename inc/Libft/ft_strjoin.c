/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:59:54 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/25 15:38:30 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		i;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	c = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ptr = (char *)malloc(sizeof(*ptr) * (c + 1));
	if (!ptr)
		return (0);
	i = 0;
	c = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		ptr[i + c] = s2[c];
		c++;
	}
	ptr[i + c] = '\0';
	return (ptr);
}
