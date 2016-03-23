/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_changes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:20:40 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/23 14:40:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, len - 1);
	data->len_a = len - (data->empty > 1 ? 1 : 0);
	data->len_b = 0;
	data->enum_moove = 0;
	data->neighbourg_less = 0;
	data->neighbourg_more = 0;
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len))) ||
	!(data->tab[1] = malloc(sizeof(int) * (len - 1))))
		return (0);
	while (i > 0)
	{
		data->tab[0][i] = ft_atoi(elements[i]);
		ft_putnbr(data->tab[0][i]);
		ft_putstr("\n");
		i--;
	}
	data->len_final = len;
	data->last_a = data->tab[0][i - 1];
	data->last_b = data->tab[0][i - 1];
	return (1);
}

void		ft_print_tab(int **tab, t_docker *data)
{
	static int tours = 0;
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, len, data->len_a);
	if (data->enum_moove > 0)
		ft_putstr("\n");
	ft_putstr("a");
	while (i < 2)
	{
		while (e < len && len > 0 && tab)
		{
			e < len ? ft_putstr(" ") : 0;
			data->empty > 2 ? ft_putcolor(data, i, e) : 0;
			ft_putnbr(data->tab[i][e]);
			data->empty > 2 ? ft_putstr("\033[0m") : 0;
			e++;
		}
		len = data->len_b;
		i++;
		e = 0;
		i == 1 ? ft_putstr("\nb") : 0;
	}
	tours++;
	if (!verif_tab(data->tab[0], data, data->len_a - 1) || data->len_b)
		ft_putstr("\n");
	else
		tours = 0;
}

/*
void		ft_print_tab(int **tab, t_docker *data)
{
	static int tours = 0;
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, len, data->len_a);
	ft_putstr("\na");
	while (i < 2)
	{
		while (e < len && len > 0 && tab)
		{
			e < len ? ft_putstr(" ") : 0;
			ft_putcolor(data, i, e);
			ft_putnbr(data->tab[i][e]);
			ft_putstr("\033[0m");
			e++;
		}
		len = data->len_b;
		i++;
		e = 0;
		i == 1 ? ft_putstr("\nb") : 0;
	}
	tours++;
	if (!verif_tab(data->tab[0], data, 0))
		ft_putstr("\n");
	else
		tours = 0;
		}*/

void		ft_memdel_tab(t_docker *data)
{
	if (data->tab)
	{
		ft_memdel((void*)&data->tab[1]);
		ft_memdel((void*)&data->tab[0]);
	}
}
