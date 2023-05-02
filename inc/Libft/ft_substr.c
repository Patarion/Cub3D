/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:18:08 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/18 12:26:37 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s);
	while (i < start && s[i] != '\0')
		i++;
	j = j - i;
	if (len < j)
		j = len;
	ptr = (char *)malloc(sizeof(*ptr) * j + 1);
	if (!ptr)
		return (0);
	j = 0;
	while (len > j && s[i + j] != '\0')
	{
		ptr[j] = s[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
