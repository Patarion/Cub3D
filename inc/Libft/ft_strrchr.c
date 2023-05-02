/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:28:27 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/14 17:52:00 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	o;
	int		i;
	int		j;

	o = (char)c;
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == o)
			j = i;
		i++;
	}
	if (s[i] == '\0' && o == '\0')
		return ((char *)(s + i));
	else if (j != -1)
		return ((char *)(s + j));
	else
		return (0);
}
