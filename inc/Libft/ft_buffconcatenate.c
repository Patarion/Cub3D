/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffconcatenate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:25 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 13:43:26 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_buffconcatenate(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	else if (!s1)
		return (ft_bufbeg(s2, ft_strlen(s2)));
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	ptr = (char *)malloc(sizeof(char *) * (i + j + 1));
	j = -1;
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2[++j] != '\0')
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free((char *) s1);
	return (ptr);
}
