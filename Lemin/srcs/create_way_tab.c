/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_way_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:38:59 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 10:40:46 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		join_road(char **road, char **cell)
{
	FT_INIT(char *, to_del, *road);
	*road = ft_strjoin(*road, " ");
	ft_strdel(&to_del);
	to_del = *road;
	*road = ft_strjoin(*road, *cell);
	ft_strdel(&to_del);
}

void		change_road(t_check *check, char **road, char **cell, int *valid)
{
	FT_INIT(char *, to_del, *road);
	if (ft_strstr(*road, check->start_cell)
	&& ft_strstr(*road, check->end_cell))
		(*valid)++;
	store_road(check, *road);
	to_del = *cell;
	*cell = new_cell(*road, check);
	ft_strdel(&to_del);
	to_del = *road;
	if (ft_strrchr(*road, ' '))
	{
		*road = ft_strsub(*road, 0,
		(ft_strlen(*road) - (ft_strlen(ft_strrchr(*road, ' ')))));
		ft_strdel(&to_del);
	}
	else
	{
		ft_strdel(&(*cell));
		*cell = ft_strdup(check->start_cell);
	}
}

char		*find_neighbor(char *road, char *name, t_check *check)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while (check->neighbor_tab[ligne])
	{
		if (!ft_strcmp(name, check->neighbor_tab[ligne][0]))
			break ;
		ligne++;
	}
	while (check->neighbor_tab[ligne] && check->neighbor_tab[ligne][colonne])
	{
		if (!ft_strstr(road, check->neighbor_tab[ligne][colonne])
		&& bad_cell(check, road, check->neighbor_tab[ligne][colonne]))
			break ;
		colonne++;
	}
	if (!check->neighbor_tab[ligne] || !check->neighbor_tab[ligne][colonne])
		return (NULL);
	return (ft_strsub(check->neighbor_tab[ligne][colonne], 0,
	ft_strlen(check->neighbor_tab[ligne][colonne])));
}

int			find_way(t_check *check)
{
	if (!check->start_cell || !check->end_cell || !check->links
	|| !check->ants)
		return (0);
	FT_INIT(int, valid, 0);
	FT_INIT(char *, to_del, NULL);
	FT_INIT(char *, cell, ft_strdup(check->start_cell));
	FT_INIT(char *, road, ft_strdup(cell));
	create_neighor_tab(check);
	while (cell)
	{
		to_del = cell;
		cell = find_neighbor(road, cell, check);
		ft_strdel(&to_del);
		if (!cell || (ft_strstr(road, check->start_cell)
		&& ft_strstr(road, check->end_cell)))
			change_road(check, &road, &cell, &valid);
		else
			join_road(&road, &cell);
	}
	ft_strdel(&cell);
	ft_strdel(&road);
	if (!valid)
		return (0);
	return (distrib_moove_ant(check));
}
