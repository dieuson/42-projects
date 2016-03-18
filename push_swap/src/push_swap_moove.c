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

int		m_ss(t_docker *data)
{
	m_sa(data);
	m_sb(data);
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
	if (data->len_a == 0)
	{
		data->empty = 'a';
		data->last_a = -99;
	}
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

int		m_rr(t_docker *data)
{
	m_ra(data);
	m_rb(data);
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

int 	distrib(int **tab, t_docker *data)
{
	FT_INIT(int, i, 0);
	data->len_a = len_tab(tab[0], data->last_a, data);
	data->len_b = (data->last_a == data->last_b ? 0 : len_tab(tab[1], data->last_b, data));
	ft_print_tab(data->tab, data);
	/*----------SA----------*/
	ft_putstr("SA-------------------------\n");
	m_sa(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("SA-------------------------\n\n");
	/*----------SA----------*/
		while (i < 8)
	{
	ft_putstr("PB-------------------------\n");
	m_pb(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("PB-------------------------\n\n");
	i++;
	}
	i = 0;
	/*----------SB----------*/
	ft_putstr("SB-------------------------\n");
	m_sb(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("SB-------------------------\n\n");
	/*----------SB----------*/
	/*----------PA----------*/
	while (i < 3)
	{
	ft_putstr("RB-------------------------\n");
	m_rb(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("RB-------------------------\n\n");
	i++;
	}
	i = 0;
	while (i < 3)
	{
	ft_putstr("RRB-------------------------\n");
	m_rrb(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("RRB------------------------\n\n");
	i++;
	}
	i = 0;
	i = 0;
	while (i < 8)
	{
	ft_putstr("PA-------------------------\n");
	m_pa(data);
	data->len_a = len_tab(data->tab[0], data->last_a, data);
	data->len_b = data->last_a == data->last_b ? 0 : len_tab(data->tab[1], data->last_b, data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("PA-------------------------\n\n");
	i++;
	}
	i = 0;
	while (i < 3)
	{
	ft_putstr("RA-------------------------\n");
	m_ra(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("RA-------------------------\n\n");
	i++;
	}
	i = 0;
	while (i < 3)
	{
	ft_putstr("RRA-------------------------\n");
	m_rra(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("RRA-------------------------\n\n");
	i++;
	}
	i = 0;
	/*----------PA----------*/
	/*----------PB----------*//*
	while (i < 8)
	{
	ft_putstr("PB-------------------------\n");
	m_pb(data);
	ft_print_tab(data->tab, data);
	printf("len_a %d, len_b %d last_a = %d, last_b = %d\n",data->len_a, data->len_b, data->last_a, data->last_b);
	ft_putstr("PB-------------------------\n\n");
	i++;
	}
	i = 0;*/
	/*----------PB----------*/
//	m_sa(data);
//	ft_print_tab(data->tab, data);
//	m_sb(data);
//	ft_print_tab(data->tab, data);
	return (1);
}


