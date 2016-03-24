/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:15:33 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/24 11:48:35 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		last_moove(t_docker *data, int ligne, int colonne)
{
	if (data->empty >= 3)
	{
		if (((data->enum_moove == sa || data->enum_moove == ss) &&
		!ligne && (colonne == data->len_a - 2 || colonne == data->len_a - 1)) ||
		((data->enum_moove == sb || data->enum_moove == ss) && ligne &&
		(colonne == data->len_b - 2 || colonne == data->len_b - 1)) ||
		((data->enum_moove == rra || data->enum_moove == ra ||
		data->enum_moove == rr) && !ligne && (colonne == data->len_a - 1
		|| colonne == 0)) || ((data->enum_moove == rrb || data->enum_moove == rb
		|| data->enum_moove == rr) && ligne && (colonne == data->len_b - 1
		|| colonne == 0)) || (data->enum_moove == pa && !ligne &&
		colonne == data->len_a - 1) || (data->enum_moove == pb && ligne
		&& colonne == data->len_b - 1))
		{
			ft_putstr("\033[");
			return (1);
		}
	}
	return (0);
}

void			ft_putcolor(t_docker *data, int ligne, int colonne)
{
	FT_INIT(char *, color, "97");
	FT_INIT(int, finish, 0);
	if (data->empty == 4)
	{
		ft_putstr("\033[");
		color = verif_tab(data->tab[0], data, data->len_a - 1) ? "32" : "31";
		finish = 1;
	}
	if (last_moove(data, ligne, colonne))
	{
		color = verif_tab(data->tab[0], data, data->len_a - 1) ? "92" : "91";
		finish = 1;
	}
	if (finish)
	{
		ft_putstr(color);
		ft_putchar('m');
	}
}
