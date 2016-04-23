#include "../includes/lem-in.h"

int 		go_ant(t_check *check, char *ant_name, char *next_cell)
{
	t_cells *tmp;

	tmp = check->start_list;
	if (!ant_name || !next_cell)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, next_cell))
		{
			ft_memdel((void*)&tmp->someone);
			tmp->someone = ft_strdup(ant_name);
			break;
		}
		tmp = tmp->next;
	}
	return (1);
}

int 		in_min_ants(t_check *check, char **good_roads)
{
	t_cells *tmp;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, nb_arg, 0);
	FT_INIT(char*, last_cell, NULL);
	tmp = check->start_list;
	while (good_roads[ligne])
	{
		last_cell = ft_strdup(ft_strrnchr(good_roads[ligne], ' ', nb_arg));
		while (last_cell)
		{
			tmp = find_cell(check, last_cell);
			go_ant(check, tmp->someone, tmp->route);
			ft_memdel((void*)&tmp->someone);
			nb_arg++;
			if (!ft_strrnchr(good_roads[ligne], ' ', nb_arg))
				break;
			ft_memdel((void*)&last_cell);
			last_cell = ft_strdup(ft_strrnchr(good_roads[ligne], ' ', nb_arg));
		}
		nb_arg = 0;
		free(last_cell);
		ligne++;
	}
	return (1);
}

int 		set_to_the_start(t_check *check, char **good_roads, t_ref *ref)
{
	t_cells *tmp;
	char 	**first_cell;

	FT_INIT(int, ligne, 0);
	tmp = check->start_list;
	while (good_roads[ligne] && ref->nb_ants_ref <= check->ants)
	{
		first_cell = ft_strsplit(good_roads[ligne], ' ');
		tmp = find_cell(check, first_cell[0]);
		ft_memdel((void*)&tmp->someone);
		ft_memdel((void*)&first_cell);
		tmp->someone = ft_strdup(named(check, ref));
		if (!tmp->someone || ref->nb_ants_ref > check->ants)
			return (0);
		ligne++;
	}
	return (1);
}

int 		moove_ants(t_check *check, t_ref *ref, char **good_roads)
{
	FT_INIT(int, nb_loops, 0);
	FT_INIT(int, verif_someone, 1);
	while (verif_someone || (!verif_someone 
	&& !ft_len_tab(good_roads) && ref->nb_ants_ref <= check->ants))
	{
		in_min_ants(check, good_roads);
		if (ref->nb_ants_ref <= check->ants)
			set_to_the_start(check, good_roads, ref);
//		ft_putstr("All GOOD ROADS\n");
//		print_simple_tab(good_roads);
//		ft_putstr("END ALL GOOD ROAD\n");
	//	printf("loops =%d,\n", nb_loops);
//		print_list(check);
		print_ants_moves(check, good_roads);
		verif_someone = verif_someone_lemin(check);
		ft_putstr("\n");
		nb_loops++;
	}
	return (0);
}

int 		distrib_moove_ant(t_check *check)
{
	t_ref	ref;
	t_cells *tmp;
	char 	**good_roads;

	good_roads = NULL;
	tmp = check->start_list;
	ref.name_ref = "L";
	ref.nb_ants_ref = 1;
	good_roads = store_good_ways(good_roads, check); 
	put_route(check, good_roads);
//	print_list(check);
	ft_putstr("All GOOD ROADS\n");
	print_simple_tab(good_roads);
	ft_putstr("END ALL GOOD ROAD\n");
	moove_ants(check, &ref, good_roads);
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}