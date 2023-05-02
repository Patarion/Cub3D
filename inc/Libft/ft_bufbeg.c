/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufbeg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:43:09 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 13:43:11 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bufbeg(const char *s, int end)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = (char *)malloc(sizeof(*ptr) * (end + 1));
	if (!ptr)
		return (0);
	while (j < end && s[j] != '\0')
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
