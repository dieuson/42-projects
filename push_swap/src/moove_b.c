/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:13:21 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/18 18:04:47 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		m_sb(t_docker *data)
{
	if (data->len_b < 2 || data->last_b == data->last_a)
		return (0);
	FT_INIT(int, tmp, data->tab[1][data->len_b - 1]);
	data->tab[1][data->len_b - 1] = data->tab[1][data->len_b - 2];
	data->tab[1][data->len_b - 2] = tmp;
	data->last_b = data->tab[1][data->len_b - 1];
	data->len_a = len_tab(data->tab[0], data->last_a, data);
	data->len_b = data->last_a == data->last_b ? 0
		: len_tab(data->tab[1], data->last_b, data);
	return (1);
}

int		m_pb(t_docker *data)
{
	if (data->len_a <= 0)
		return (0);
	data->enum_moove = pb;
	data->last_a = data->tab[0][data->len_a - 2];
	data->last_b = data->tab[0][data->len_a - 1];
	resize_tab(data, data->len_a - 1, data->len_b + 1);
	data->len_a--;
	data->len_b++;
	if (data->len_a <= 0)
	{
		data->empty = 'a';
		data->last_a = -99;
	}
	return (1);
}

int		m_rb(t_docker *data)
{
	if (data->len_b < 2)
		return (0);
	FT_INIT(int, i, data->len_b - 1);
	FT_INIT(int, tmp2, data->tab[1][data->len_b - 1]);
	while (i > 0)
	{
		data->tab[1][i] = data->tab[1][i - 1];
		i--;
	}
	data->tab[1][0] = tmp2;
	data->last_b = data->tab[1][data->len_b - 1];
	if (data->len_b == 0)
		data->last_b = data->last_a;
	return (1);
}

int		m_rrb(t_docker *data)
{
	if (data->len_b < 2)
		return (0);
	FT_INIT(int, i, 0);
	FT_INIT(int, tmp2, data->tab[1][0]);
	while (i < data->len_b)
	{
		data->tab[1][i] = data->tab[1][i + 1];
		i++;
	}
	data->tab[1][data->len_b - 1] = tmp2;
	data->last_b = data->tab[1][data->len_b - 1];
	if (data->len_b == 0)
		data->last_b = data->last_a;
	return (1);
}
