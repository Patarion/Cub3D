/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:49:15 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/19 14:27:48 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_nbwords(char	const *s, char c);
size_t	ft_wordlengh(char const *s, char c, size_t i);
char	*ft_writeword(char const *s, char c, size_t i);

size_t	ft_nbwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (i < ft_strlen(s))
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

size_t	ft_wordlengh(char const *s, char c, size_t i)
{
	size_t	lengh;

	lengh = 0;
	while (s[i] != c && i < ft_strlen(s))
	{
		lengh++;
		i++;
	}
	return (lengh);
}

char	*ft_write_word(char const *s, char c, size_t i)
{
	char	*word;
	size_t	x;

	word = (char *)malloc(sizeof(*word) * (ft_wordlengh(s, c, i) + 1));
	if (!word)
		return (0);
	x = 0;
	while (s[i + x] != c && (i + x) < ft_strlen(s))
	{
		word[x] = s[i + x];
		x++;
	}
	word[x] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	count = ft_nbwords(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (count > 0)
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		tab[y] = ft_write_word(s, c, i);
		y++;
		count--;
		i = i + ft_wordlengh(s, c, i);
	}
	tab[y] = NULL;
	return (tab);
}
