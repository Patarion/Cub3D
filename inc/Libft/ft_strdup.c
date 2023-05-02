/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:27:34 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/18 16:38:08 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1);

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	if (s1 == NULL)
		return(NULL);
	i = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(*ptr) * i);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, (char *)s1, i);
	return (ptr);
}
