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
	while (data->pos_tab[i] && tab)
	{ 
		if (tab[i] != data->pos_tab[i])
			return (0);
		i++;
	}
	return (1);

}
int 	distrib(int **tab, t_docker *data)
{
	static int tours = 0;
	if (tours == 0)
		ft_print_tab(tab, data);
	if (data->last_a > tab[0][data->len_a - 2] && data->len_a > 1)
	{
		m_sa(data);
		ft_print_tab(tab, data);
		ft_putstr("SA\n");
	}
	else if (data->last_a > tab[0][0] && data->last_a > tab[0][data->len_a - 2] && data->len_a > 1)
	{
		m_ra(data);
		ft_print_tab(tab, data);
		ft_putstr("RA\n");
	}
	else if (data->last_a > tab[0][0] && data->len_a > 1)
	{
		m_rra(data);
		ft_print_tab(tab, data);
		ft_putstr("RRA\n");
	}
	else if (data->last_a < tab[0][0] && data->last_a < tab[0][data->len_a - 2] && data->last_a >= data->last_b && data->len_a > 1)
	{
		m_pb(data);
		ft_print_tab(tab, data);
		ft_putstr("PB\n");
	}
	else if (data->last_b < tab[1][data->len_b - 2] && data->len_b > 1)
	{
		m_sb(data);
		ft_print_tab(tab, data);
		ft_putstr("SB\n");
	}
	else if (data->last_b < tab[1][0] && data->last_b < tab[1][data->len_b - 2] && data->len_b > 1)
	{
		m_rb(data);
		ft_print_tab(tab, data);
		ft_putstr("RB\n");
	}
	else if (data->last_b < tab[1][0] && data->len_b > 1)
	{
		m_rrb(data);
		ft_print_tab(tab, data);
		ft_putstr("RRB\n");
	}
	else if (data->last_b > tab[1][0] && data->last_b > tab[1][data->len_b - 2] && data->last_a > data->last_b && data->len_b > 0)
	{
		m_pa(data);
		ft_print_tab(tab, data);
		ft_putstr("PA\n");
	}
	printf("last_a = %d, last_b = %d, len_a = %d, len_b = %d\n", data->last_a, data->last_b, data->len_a, data->len_b);
	tours++;
	if (!verif_tab(data->tab[0], data) && tours <= 10)
		distrib(data->tab, data);
//	ft_putstr("tet5\n");
	return (1);
}
