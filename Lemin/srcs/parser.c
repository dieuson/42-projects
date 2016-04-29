/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 08:02:38 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:07:24 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int			start_end_min(char *line, t_check *check)
{
	if (line && !ft_strcmp("##start", line))
		return (check->start = 1);
	else if (line && !ft_strcmp("##end", line))
		return (check->end = 1);
	return (0);
}

int			len_tab(char **tab)
{
	FT_INIT(int, i, 0);
	while (tab && tab[i])
		i++;
	return (i);
}

int			verif_double(t_cells **cells, t_check *check)
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
