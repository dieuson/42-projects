/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:12:04 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/18 14:29:03 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			push_swap(int argc, char **elements)
{
	t_docker data;

	if (!check_push_swap(elements))
		return (-1);
	init_tab(&data, argc, elements);
	if (!check_doublon(*data.tab, data.len_a))
	{
		ft_memdel((void*)&data.pos_tab);
		ft_memdel_tab(&data);
		return (-2);
	}
//	ft_print_tab(data.tab, &data);
//	print_result(data.pos_tab, data.len_a);
	distrib(data.tab, &data);
//	ft_memdel_tab(&data);
//	ft_memdel((void*)&data.pos_tab);
	return (0);
}

int main(int argc, char **argv)
{
	FT_INIT(int, err, 0);
	if (argc > 1)
	{
		err = push_swap((argc - 1), argv + 1);
		if (err == -1)
			ft_putstr("Error char\n");
		if (err == -2)
			ft_putstr("Error doublon\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
