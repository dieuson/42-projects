/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:08:18 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 16:00:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(int n)
{
	int		i;

	i = 0;
	if (!n)
		return (0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_signe(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		lenght;
	int		signe;

	signe = ft_signe(n);
	if (!(s = ft_strnew(ft_lenght(n) + signe)))
		return (NULL);
	if (ft_signe(n) == 1)
		n = -n;
	lenght = ft_lenght(n) + signe;
	s[lenght] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (n != 0)
	{
		s[--lenght] = ((n % 10) + '0');
		n /= 10;
	}
	if (signe == 1)
		s[--lenght] = '-';
	return (s);
}
