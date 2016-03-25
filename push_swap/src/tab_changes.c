/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_changes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:20:40 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/25 14:10:13 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, 0);
	FT_INIT(long int, nb, 0);
	data->enum_moove = 0;
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len + 1))) ||
	!(data->tab[1] = malloc(sizeof(int) * (len + 1))))
		return (0);
	while (len > 0 + (data->empty > 1 ? 1 : 0))
	{
		nb = ft_atoi(elements[len - 1]);
		if (nb < -2147483648 || nb > 2147483647
			|| (ft_strchr("+-", elements[len - 1][0])
				&& (!ft_strchr("0123456789", elements[len - 1][1])
					|| !elements[len - 1][1])))
			return (0);
		data->tab[0][i] = nb;
		i++;
		len--;
	}
	data->len_a = i;
	data->len_b = 0;
	data->last_a = data->tab[0][i - 1];
	data->last_b = data->tab[0][i - 1];
	return (1);
}

static void		print_details(t_docker *data, int nb)
{
	if (data->empty > 0 && data->empty < 4)
		ft_putstr("\n");
	if (data->empty == 4)
	{
		if (verif_tab(data->tab[0], data, data->len_a - 1)
			&& !data->len_b && nb == 1)
			nb = 0;
		ft_putstr("---------------------------------------\nmoove : ");
		print_moove(data);
		ft_putstr("	laps: ");
		ft_putnbr(nb);
		ft_putstr("			");
		ft_putstr("\n---------------------------------------\n");
	}
}

void			ft_print_tab(int **tab, t_docker *data)
{
	static int tours = 1;

	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, len, data->len_a);
	print_details(data, tours);
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
}

void			ft_memdel_tab(t_docker *data)
{
	if (data->tab)
	{
		ft_memdel((void*)&data->tab[1]);
		ft_memdel((void*)&data->tab[0]);
	}
}
