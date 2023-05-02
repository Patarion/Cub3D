/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:14:50 by jgagnon           #+#    #+#             */
/*   Updated: 2021/10/27 14:39:01 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int		ft_nblengh(int n);
char	*ft_putchar(char *str, int n, int i);

int	ft_nblengh(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_putchar(char *str, int n, int i)
{
	int	max;

	max = 0;
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
		max++;
	}
	str[i] = '\0';
	while (i-- > max)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nblengh(n);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (0);
	str = ft_putchar(str, n, i);
	return (str);
}
