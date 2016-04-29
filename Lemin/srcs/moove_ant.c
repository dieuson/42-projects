/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:52:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:07:03 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			go_ant(char **route, t_check *check, char *ant, char *next_cell)
{
	t_cells	*tmp;

	tmp = check->start_list;
	if (!ant || !next_cell)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, next_cell))
		{
			ft_strdel(&tmp->someone);
			tmp->someone = ft_strdup(ant);
			print_route(route, tmp->someone, tmp->name);
			break ;
		}
		tmp = tmp->next;
	}
	return (1);
}

int			in_min_ants(char **route, t_check *check, t_ref *ref)
{
	t_cells	*tmp;

	FT_INIT(int, nb_ants, 1);
	tmp = find_ant_nb(nb_ants, check);
	while (nb_ants <= ref->nb_ants_ref)
	{
		if (tmp)
		{
			go_ant(route, check, tmp->someone, tmp->route);
			ft_strdel(&tmp->someone);
		}
		nb_ants++;
		tmp = find_ant_nb(nb_ants, check);
	}
	return (1);
}

int			set_to_start(char **road, t_check *check, char **tab, t_ref *ref)
{
	t_cells	*tmp;
	char	**first_cell;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, addition, 0);
	tmp = check->start_list;
	while (ligne <= calc_last_ligne(check, ref) && tab[ligne]
	&& ref->nb_ants_ref <= check->ants)
	{
		first_cell = ft_strsplit(tab[ligne], ' ');
		tmp = find_cell(check, first_cell[0]);
		ft_memdel((void*)&tmp->someone);
		free_simple_tab(&first_cell);
		tmp->someone = named(check, ref);
		print_route(road, tmp->someone, tmp->name);
		addition += check->line_length[ligne];
		if (!tmp->someone || ref->nb_ants_ref > check->ants)
			return (0);
		ligne++;
	}
	return (1);
}

int			moove_ants(t_check *check, t_ref *ref, char **good_roads)
{
	FT_INIT(int, nb_loops, 0);
	FT_INIT(int, verif_someone, 1);
	FT_INIT(char*, route, NULL);
	while (verif_someone || ref->nb_ants_ref <= check->ants)
	{
		in_min_ants(&route, check, ref);
		if (ref->nb_ants_ref <= check->ants)
			set_to_start(&route, check, good_roads, ref);
		verif_someone = verif_someone_lemin(check);
		ft_putstr(route);
		ft_putstr("\n");
		ft_memdel((void*)&route);
		nb_loops++;
	}
	return (0);
}

int			distrib_moove_ant(t_check *check)
{
	t_ref	ref;
	t_cells	*tmp;

	FT_INIT(char**, good_roads, NULL);
	tmp = check->start_list;
	ref.name_ref = "L";
	ref.nb_ants_ref = 1;
	good_roads = store_good_ways(check);
	put_route(check, good_roads);
	check->line_length =
	store_length_line(good_roads, &check->line_length_min);
	moove_ants(check, &ref, good_roads);
	free_simple_tab(&good_roads);
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}
