/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:25 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/23 12:15:05 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char	f;
	char	*ptr;

	f = (char)c;
	ptr = (char *)s;
	while (*ptr != '\0' && *ptr != f)
		ptr++;
	if (*ptr == f)
		return (ptr);
	else if (f == '\0' && *ptr == '\0')
		return (ptr);
	else
		return (0);
}
