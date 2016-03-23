/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:36:35 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/23 14:49:49 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int		push_swap(int argc, char **elements)
{
	t_docker data;

	if (!(data.empty = check_push_swap(elements)))
		return (-1);
	init_tab(&data, argc, elements);
	if (!data.empty || !check_doublon(*data.tab, data.len_a))
	{
		ft_memdel_tab(&data);
		return (-2);
	}
	if (argc == 1)
	{
		ft_print_tab(data.tab, &data);
		return (1);
	}
	distrib(data.tab, &data);
	ft_putstr("\n");
	ft_memdel_tab(&data);
	return (0);
}

int		main(int argc, char **argv)
{
	FT_INIT(int, err, 0);

	if (argc > 1)
	{
		err = push_swap((argc - 1), argv + 1);
		if (err == -1)
			ft_putstr("Error\n");
		if (err == -2)
			ft_putstr("Error\n");
	}
	else
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}
