/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:13:21 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 12:58:36 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int verif_tab(int *tab, t_docker *data, int len)
{
	FT_INIT(int, i, 0);
	while (data->pos_tab[i] && i < (len ? len : data->len_final))
	{
		if (tab[i] != data->pos_tab[i])
			return (0);
		i++;
	}
	if (data->last_a != tab[i - 1])
		return (0);
	return (1);

}
int 	distrib(int **tab, t_docker *data)
{
	static int tours = 0;
	if (tours == 0)
	{
		print_result(data->pos_tab, data->len_a);
	}
	if (data->len_a > 1 && data->last_a > tab[0][data->len_a - 2])
	{
		m_sa(data);
		ft_putstr("SA ");
	}
	else if (data->len_a > 1 && data->last_a > tab[0][0]
			 && data->last_a > tab[0][data->len_a - 2])
	{
		m_ra(data);
		ft_putstr("RA ");
	}
	else if (data->len_a > 1 && tab[0][0] < data->last_a  && data->last_a < tab[0][data->len_a - 2])
	{
		m_rra(data);
		ft_putstr("RRA ");
	}
	else if (data->len_a > 1 && data->last_a >= data->last_b && data->last_a < data->tab[0][0]
			 && !verif_tab(data->tab[0], data, data->len_a))
	{
		m_pb(data);
		ft_putstr("PB ");
	}
	else if (data->len_b > 1 && data->last_b < tab[1][data->len_b - 2])
	{
		m_sb(data);
		ft_putstr("SB ");
	}
	else if (data->len_b > 1 && data->last_b < tab[1][0]
			 && data->last_b < tab[1][data->len_b - 2])
	{
		m_rb(data);
		ft_putstr("RB ");
	}
	else if (data->len_b > 1 && data->last_b < tab[1][0])
	{
		m_rrb(data);
		ft_putstr("RRB ");
	}
	else if (data->len_b && data->last_a >= data->last_b && data->last_a < data->tab[0][0]
			 && verif_tab(data->tab[0], data, data->len_a))
	{
		m_pa(data);
		ft_putstr("PA ");
	}
	tours++;
	if (tours == 50)
		ft_putstr("\nRISQUE SEGFAULT\n");
	if (!verif_tab(data->tab[0], data, 0) && tours <= 50)
			distrib(data->tab, data);
	else
		tours = 0;
	return (1);
}
