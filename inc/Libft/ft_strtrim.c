/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:23:20 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/25 15:39:20 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_findbeg(char const *s1, char const *set);
int		ft_findend(char const *s1, char const *set);

int	ft_findbeg(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (set[j] != s1[i] && set[j] != '\0')
			j++;
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		if (set[j] == '\0')
			return (i);
	}
	if (i == ft_strlen(s1))
		return (i - 1);
	return (0);
}

int	ft_findend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (i > 0)
	{
		while (set[j] != s1[i] && set[j] != '\0')
			j++;
		if (set[j] == s1[i])
		{
			i--;
			j = 0;
		}
		if (set[j] == '\0')
			return (i + 1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	beg;
	size_t	end;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	beg = ft_findbeg(s1, set);
	end = ft_findend(s1, set);
	if (beg >= end)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(*ptr) * (end - beg + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + beg, end - beg + 1);
	return (ptr);
}
