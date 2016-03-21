/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_changes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:20:40 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 15:21:02 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, 0);
	data->len_a = len;
	data->empty = 0;
	data->len_b = 0;
	data->neighbourg_less = 0;
	data->neighbourg_more = 0;
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len))) ||
	!(data->pos_tab = malloc(sizeof(int) * (len))) ||
	!(data->tab[1] = malloc(sizeof(int) * (1))))
		return (0);
	while (i < len)
	{
		data->pos_tab[i] = ft_atoi(elements[i]);
		data->tab[0][i] = ft_atoi(elements[i]);
		i++;
	}
	data->len_final = i;
	data->last_a = data->tab[0][i - 1];
	data->last_b = data->tab[0][i - 1];
	data->tab[1] = NULL;
	data->pos_tab = sort_int_tab(data->pos_tab, data);
	return (1);
}

void		ft_print_tab(int **tab, t_docker *data)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, len, data->len_a);
	ft_putstr("a");
	while (i < 2)
	{
		while (e < len && len > 0 && tab)
		{
			e < len ? ft_putstr(" ") : 0;
			ft_putnbr(data->tab[i][e]);
			e++;
		}
		len = data->len_b;
		i++;
		ft_putstr("\n");
		i == 1 ? ft_putstr("b") : 0;
		e = 0;
	}
	ft_putstr("\n");
}

void		ft_memdel_tab(t_docker *data)
{
	if (data->tab)
	{
		ft_memdel((void*)&data->tab[1]);
		ft_memdel((void*)&data->tab[0]);
	}
}
