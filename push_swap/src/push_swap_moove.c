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
#include <stdio.h>

int verif_tab(int *tab, t_docker *data)
{
	FT_INIT(int, i, 0);
	while (data->pos_tab[i])
	{
		if (tab[i] != data->pos_tab[i])
			return (0);
		i++;
	}
	return (1);

}
int 	distrib(int **tab, t_docker *data)
{
	ft_print_tab(tab, data);
	if (tab[0][data->len_a - 1] > tab[0][data->len_a - 2])
	{
		ft_putstr("test\n");
		m_sa(data);
		ft_print_tab(tab, data);
		ft_putstr("SA\n");
	}
	if (tab[0][data->len_a - 1] > tab[0][0] && tab[0][data->len_a - 1] > tab[0][data->len_a - 2])
	{
		ft_putstr("test1\n");
		m_ra(data);
		ft_print_tab(tab, data);
		ft_putstr("RA\n");
	}
	if (tab[0][data->len_a - 1] > tab[0][0])
	{
		m_rra(data);
		ft_print_tab(tab, data);
		ft_putstr("RRA\n");
	}
	if (tab[0][data->len_a - 1] < (tab[1][data->len_b - 1] ? tab[1][data->len_b - 1] : 0) && tab[0][data->len_a - 1] < tab[0][0])
	{
		m_pb(data);
		ft_print_tab(tab, data);
		ft_putstr("PB\n");
	}
	if (!verif_tab(data->tab[0], data))
		distrib(tab, data);
	return (1);
}