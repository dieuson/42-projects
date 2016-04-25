/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 08:02:38 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/07 16:02:43 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int			check_nb_args(char *line)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, nb_args, 0);
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_strchr(" ", line[i]) && line[i])
			nb_args++;
		while (!ft_strchr(" ", line[i]) && line[i])
			i++;
		while (ft_strchr(" ", line[i]) && line[i])
			i++;
		if (nb_args && !ft_strchr(" 0123456789", line[i]))
			return (0);
	}
	return (nb_args);
}

int 		verif_double(t_cells **cells, t_check *check)
{
	FT_INIT(int, nb_args, 0);
	FT_INIT(t_cells *, tmp, check->start_list);
	while (tmp->next)
	{
		nb_args++;
		tmp = tmp->next;
	}
	tmp = check->start_list;
	while (tmp->next && nb_args)
	{
		if (!ft_strcmp(tmp->name, (*cells)->name))
			return (0);
		else if (tmp->pos_x == (*cells)->pos_x && tmp->pos_y == (*cells)->pos_y)
			return (0);
		nb_args--;
		tmp = tmp->next;
	}
	return (1);
}

int			build_list(t_cells **cells, t_check *check, char *line)
{
	FT_INIT(int, nb_args, check_nb_args(line));
	if (nb_args == 3)
	{
		(*cells)->next = create_cells(line);
		*cells = (*cells)->next;
		if (check->start)
			check->start_cell = (*cells)->name;
		else if (check->end)
			check->end_cell = (*cells)->name;
		check->start = 0;
		check->end = 0;
		if (!verif_double(cells, check))
			return (0);
	}
	if (nb_args == 1 && (!check->start_cell 
	|| !check->end_cell || !link_cells(check->start_list, check, line)))
		return (0);
	check->nb_args++;
	return (1);
}