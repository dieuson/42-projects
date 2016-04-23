#include "../includes/lem-in.h"

void 		print_list(t_check *check)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		printf("tmp->name =%s, tmp->route =%s, tmp->someone =%s\n", tmp->name, tmp->route, tmp->someone);
		tmp = tmp->next;
	}
}

char 		*named(t_check *check, t_ref *ref)
{
	char 	*ant_name;

	if (ref->nb_ants_ref > check->ants)
		return (NULL);
	ant_name = ref->name_ref;
	ant_name = ft_strjoin(ant_name, ft_itoa(ref->nb_ants_ref));
	ref->nb_ants_ref++;
	return (ant_name);
}

char 		**short_way(char **tab)
{
	FT_INIT(char *, tmp, NULL);
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	while (tab[ligne])
	{
		while (tab[ligne2])
		{
			if (nb_cells(tab[ligne2]) < nb_cells(tab[ligne]))
			{
				tmp = tab[ligne];
				tab[ligne] = tab[ligne2];
				tab[ligne2] = tmp;
			}	
			ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
	return (tab);
}

void 		put_route(t_check *check, char **good_roads)
{
	t_cells *tmp;
	char 	*cell;

	FT_INIT(int, ligne, 0);
	tmp = check->start_list;
	while (good_roads[ligne])
	{
		cell = good_roads[ligne];
		while (tmp)
		{
			if (!(first(cell)) || !ft_strchr(cell, ' '))
				break;
			if (!ft_strcmp(first(cell), tmp->name))
			{
				cell = ft_strchr(cell, ' ') + 1;
				tmp->route = first(cell);
				tmp = check->start_list;
			}
			tmp = tmp->next;
		}
		ligne++;
		tmp = check->start_list;
	}
}

t_cells		*find_cell(t_check *check, char *cell_name)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, cell_name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char 		*ft_strrnchr(char *str, int c, int nb)
{
	char 	**tab;
	char 	*tmp_str;

	FT_INIT(int, end, 0);
	if (!str || !c)
		return (NULL);
	tab = ft_strsplit(str, c);
	if (!tab)
		return (NULL);
	while (tab[end])
			end++;
	end--;
	if (nb > end || end < 0)
		return (NULL);
	tmp_str = ft_strdup(tab[end - nb]);
	if (tmp_str)
		return (tmp_str);
	else
		return (NULL);
}

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
			free(tmp->someone);
			tmp->someone = ft_strdup(ant_name);
			break;
		}
		tmp = tmp->next;
	}
	return (1);
}

int 		ft_len_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab && tab[ligne])
		ligne++;
	ligne--;
	if (!ligne)
		if (!ft_strchr(tab[ligne], ' '))
				return (0);
	return (1);
}

int 		verif_someone_lemin(t_check *check)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->someone && ft_strcmp(tmp->name, check->end_cell))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void 		print_ants_moves(t_check *check, char **good_roads)
{
	t_cells *tmp;
	static char *reste = NULL;

	FT_INIT(int, nb, 1);
	FT_INIT(char*, route, NULL);
	tmp = check->start_list;
	if (reste)
	{
		route = ft_strdup(reste);
		ft_memdel((void*)&reste);
	}
	while (nb <= check->ants)
	{
		while (tmp)
		{
			if (tmp->someone && ft_atoi(ft_strchr(tmp->someone, 'L') + 1) == nb)
			{
				if (!ft_len_tab(good_roads))
				{
					route = ft_strdup(tmp->someone);
					route = ft_strjoin(route, "-");
					route = ft_strjoin(route, tmp->name);
				}
				if (route && tmp->someone && tmp->route)
				{
					route = ft_strjoin(route, " ");
					route = ft_strjoin(route, tmp->someone);
					route = ft_strjoin(route, "-");
					route = ft_strjoin(route, tmp->name);
					if (!ft_strcmp(tmp->route, check->end_cell))
					{
//						printf("tmp->someone =%s, tmp->cell =%s, tmp->route =%s,\n", tmp->someone,tmp->name, tmp->route);
						if (reste)
						{
							reste = ft_strjoin(reste, " ");
							reste = ft_strjoin(reste, tmp->someone);						
						}
						else
							reste = ft_strdup(tmp->someone);
						reste = ft_strjoin(reste, "-");
						reste = ft_strjoin(reste, tmp->route);
					}
				}
				else if (!route && tmp->someone && tmp->route)
				{
					route = ft_strdup(tmp->someone);
					route = ft_strjoin(route, "-");
					route = ft_strjoin(route, tmp->name);
					if (!ft_strcmp(tmp->route, check->end_cell))
					{
//						printf("else tmp->someone =%s, tmp->cell =%s, tmp->route =%s,\n", tmp->someone,tmp->name, tmp->route);
						reste = ft_strdup(tmp->someone);
						reste = ft_strjoin(reste, "-");
						reste = ft_strjoin(reste, tmp->route);
					}
				}
//				printf("reste =%s,\n", reste);
			}
			tmp = tmp->next;
		}
		nb++;
		tmp = check->start_list;
	}
	ft_putstr(route);
	ft_memdel((void*)&route);
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
	//		printf("parcours =%s, someone =%s, name =%s,\n", parcours, tmp->someone, tmp->name);
			go_ant(check, tmp->someone, tmp->route);
			free(tmp->someone);
			tmp->someone = NULL;
			nb_arg++;
			if (!ft_strrnchr(good_roads[ligne], ' ', nb_arg))
				break;
			free(last_cell);
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
		ft_memdel((void*)tmp->someone);
		ft_memdel((void*)first_cell);
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
	while (verif_someone || (!verif_someone && !ft_len_tab(good_roads) && ref->nb_ants_ref <= check->ants))
	{
		in_min_ants(check, good_roads);
		if (ref->nb_ants_ref <= check->ants)
		{
			set_to_the_start(check, good_roads, ref);
//			ft_putstr("test7\n");
		}
//		ft_putstr("All GOOD ROADS\n");
//		print_simple_tab(good_roads);
//		ft_putstr("END ALL GOOD ROAD\n");
	//	printf("loops =%d,\n", nb_loops);
//		print_list(check);
		print_ants_moves(check, good_roads);
		ft_putstr("\n");
		verif_someone = verif_someone_lemin(check);
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
	moove_ants(check, &ref, good_roads);
	ft_putstr("All GOOD ROADS\n");
	print_simple_tab(good_roads);
	ft_putstr("END ALL GOOD ROAD\n");
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}