/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:53:43 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/27 14:34:19 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				i;
	int				signe;

	nb = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 0x09 && str[i] <= 0x0d) || str[i] == 0x20)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		nb = (nb * 10) + (str[i] - 0x30);
		i++;
	}
	return (nb * signe);
}
