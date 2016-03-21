/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_expected.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:19:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 15:20:14 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_result(int *result, int len)
{
	FT_INIT(int, i, 0);
	ft_putstr("RESULT\n");
	while (i < len)
	{
		ft_putnbr(result[i]);
		result[i + 1] ? ft_putstr(" ") : 0;
		i++;
	}
	ft_putstr("\n\n");
}

int			*sort_int_tab(int *tab, t_docker *data)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 1);
	FT_INIT(int, min, 0);
	while (i < data->len_a)
	{
		while (tab[i] < tab[e] && e < data->len_a)
			e++;
		if (tab[i] > tab[e] && e < data->len_a)
		{
			min = tab[i];
			tab[i] = tab[e];
			tab[e] = min;
			i = 0;
		}
		else
			i++;
		e = 0;
	}
	return (tab);
}
