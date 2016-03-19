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
	return (1);
}


