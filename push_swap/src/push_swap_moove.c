/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:06:32 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 15:13:46 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				verif_tab(int *tab, t_docker *data, int len)
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

static void		moove_aux(int **tab, t_docker *data)
{
	if ((data->len_a > 1 && data->last_a > tab[0][data->len_a - 2]) &&
		(data->len_b > 1 && data->last_b < tab[1][data->len_b - 2]))
		m_ss(data);
	else if (data->len_a > 1 && data->last_a > tab[0][0]
		&& data->last_a > tab[0][data->len_a - 2]
		&& data->len_b > 1 && data->last_b < tab[1][0]
		&& data->last_b < tab[0][data->len_b - 2])
		m_rr(data);
	else if (data->len_a > 1 && tab[0][0] < data->last_a
		&& data->last_a < tab[0][data->len_a - 2]
		&& data->len_b > 1 && tab[1][0] > data->last_b
		&& data->last_b < tab[1][data->len_b - 2])
		m_rrr(data);
}

static	void	print_moove(t_docker *data)
{
	if (data->enum_moove == sa)
		ft_putstr("sa");
	else if (data->enum_moove == sb)
		ft_putstr("sa");
	else if (data->enum_moove == ss)
		ft_putstr("ss");
	else if (data->enum_moove == pa)
		ft_putstr("pa");
	else if (data->enum_moove == pb)
		ft_putstr("pb");
	else if (data->enum_moove == ra)
		ft_putstr("ra");
	else if (data->enum_moove == rb)
		ft_putstr("rb");
	else if (data->enum_moove == rr)
		ft_putstr("rr");
	else if (data->enum_moove == rra)
		ft_putstr("rra");
	else if (data->enum_moove == rrb)
		ft_putstr("rrb");
	else if (data->enum_moove == rrr)
		ft_putstr("rrr");
	if (!verif_tab(data->tab[0], data, 0))
		ft_putstr(" ");
}

int				distrib(int **tab, t_docker *data)
{
	moove_aux(tab, data);
	data->empty > 1 ? ft_print_tab(tab, data) : 0;
	if (data->len_a > 1 && data->last_a > tab[0][data->len_a - 2])
		m_sa(data);
	else if (data->len_b > 1 && data->last_b < tab[1][data->len_b - 2])
		m_sb(data);
	else if (data->len_a > 1 && data->last_a > tab[0][0]
		&& data->last_a > tab[0][data->len_a - 2])
		m_ra(data);
	else if (data->len_b > 1 && data->last_b < tab[1][0]
		&& data->last_b < tab[0][data->len_b - 2])
		m_rb(data);
	else if (data->len_a > 1 && tab[0][0] < tab[0][1])
		m_rra(data);
	else if (data->len_b > 1 && tab[1][0] > data->last_b
		&& data->last_b < tab[1][data->len_b - 2])
		m_rrb(data);
	else if (data->len_a > 1 && data->last_a >= data->last_b
		&& !verif_tab(data->tab[0], data, data->len_a))
		m_pb(data);
	else if (data->len_b && !verif_tab(data->tab[0], data, data->len_a - 1))
		m_pa(data);
	print_moove(data);
	if (!verif_tab(data->tab[0], data, 0))
		distrib(data->tab, data);
	return (1);
}