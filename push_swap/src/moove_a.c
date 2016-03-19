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

int		m_sa(t_docker *data)
{
	if (data->empty == 'a')
		return (0);
	FT_INIT(int, tmp, 0);
	tmp = data->tab[0][data->len_a - 1];
	data->tab[0][data->len_a - 1] = data->tab[0][data->len_a - 2];
	data->tab[0][data->len_a - 2] = tmp;
	data->last_a = data->tab[0][data->len_a - 1];
	if (data->len_b == 0)
		data->last_b = data->last_a;
	return (1);
}

int		m_pa(t_docker *data)
{
	if (data->len_b <= 0)
		return (0);
	data->enum_moove = pa;
	data->last_a = data->tab[1][data->len_b - 1];
	data->last_b = data->len_b > 1 ? data->tab[1][data->len_b - 2]
		: data->last_a;
	resize_tab(data, data->len_a + 1, data->len_b - 1);
	data->len_a++;
	return (1);
}

int		m_ra(t_docker *data)
{
	if (data->len_a < 2)
		return (0);
	FT_INIT(int, i, data->len_a - 1);
	FT_INIT(int, tmp2, data->tab[0][data->len_a - 1]);
	while (i > 0)
	{
		data->tab[0][i] = data->tab[0][i - 1];
		i--;
	}
	data->tab[0][0] = tmp2;
	data->last_a = data->tab[0][data->len_a - 1];
	if (data->len_b == 0)
		data->last_b = data->last_a;
	return (1);
}

int		m_rra(t_docker *data)
{
	if (data->len_a < 2)
		return (0);
	FT_INIT(int, i, 0);
	FT_INIT(int, tmp2, data->tab[0][0]);
	while (i < data->len_a)
	{
		data->tab[0][i] = data->tab[0][i + 1];
		i++;
	}
	data->tab[0][data->len_a - 1] = tmp2;
	data->last_a = data->tab[0][data->len_a - 1];
	if (data->len_b == 0)
		data->last_b = data->last_a;
	return (1);
}