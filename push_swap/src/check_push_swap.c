/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:06:43 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 15:07:06 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_push_swap(char **elements)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, check, 0);
	if (!ft_strcmp(elements[0],"-v") || !ft_strcmp(elements[0],"-c") 
		|| !ft_strcmp(elements[0],"-d"))
	{
		check = !ft_strcmp(elements[0],"-v") ? 1 : check;
		check = !ft_strcmp(elements[0],"-c") ? 2 : check;
		check = !ft_strcmp(elements[0],"-d") ? 3 : check;
		elements++;
	}
	while (elements[e])
	{
		while (elements[e][i])
		{
			if (!ft_strchr("-+0123456789", elements[e][i]))
				return (0);
			i++;
		}
		e++;
		i = 0;
	}
	return (1 + check);
}

int		check_doublon(int *tab, int len)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 1);
	while (i < len)
	{
		while (e < len)
		{
			if (tab[i] == tab[e])
				return (0);
			e++;
		}
		i++;
		e = i + 1;
	}
	return (1);
}
