/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:13:21 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/24 15:40:37 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		resize_tab(t_docker *data, int len_a, int len_b)
{
	if (len_a || len_b)
		len_a = len_b;
	if (data->enum_moove == pb)
		data->tab[1][data->len_b] = data->last_b;
	else
		data->tab[0][data->len_a] = data->last_a;
	return (1);
}

int		m_ss(t_docker *data)
{
	m_sa(data);
	m_sb(data);
	data->enum_moove = ss;
	return (1);
}

int		m_rr(t_docker *data)
{
	m_ra(data);
	m_rb(data);
	data->enum_moove = rr;
	return (1);
}

int		m_rrr(t_docker *data)
{
	m_rra(data);
	m_rrb(data);
	data->enum_moove = rrr;
	return (1);
}
