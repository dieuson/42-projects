/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:15:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/24 14:53:57 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int		ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			signe;

	signe = 1;
	i = 0;
	result = 0;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - 48);
		else
			return (signe * result);
		i++;
	}
	return (signe * result);
}
