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

int	resize_tab(t_docker *data, int len_a, int len_b)
{
	FT_INIT(int**, tmp, NULL);
	if (!(tmp = malloc(sizeof(int*) * 2)) ||
	!(tmp[0] = malloc(sizeof(int) * (data->len_a))) ||
	!(tmp[1] = malloc(sizeof(int) * (data->len_b))))
	return (0);
	tab_copy(data->tab, tmp, data->len_a, data->len_b);
	ft_memdel_tab(data);
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len_a))) ||
	!(data->tab[1] = malloc(sizeof(int) * (len_b))))
		return (0);
	tab_copy(tmp, data->tab, len_a, len_b);
	if (data->enum_moove == pb)
		data->tab[1][data->len_b] = tmp[0][data->len_a - 1];
	else
		data->tab[0][data->len_a] = tmp[1][data->len_b - 1];
	ft_memdel((void*)&tmp[0]);
	ft_memdel((void*)&tmp[1]);
	return (1);
}

int		m_ss(t_docker *data)
{
	m_sa(data);
	m_sb(data);
	return (1);
}

int		m_rr(t_docker *data)
{
	m_ra(data);
	m_rb(data);
	return (1);
}

int		m_rrr(t_docker *data)
{
	m_rra(data);
	m_rrb(data);
	return (1);
}

int 	len_tab(int *tab, int last, t_docker *data)
{
	FT_INIT(int, i, 0);
	if (data)
		i = 0;
	while (tab[i] != last && tab[i])
		i++;
	if (tab[i] == last)
		i++;
	return (i);
}