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

	if (!ref || ref->nb_ants_ref > check->ants)
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

	printf("str =%s, nb =%d,\n",str, nb);
	FT_INIT(int, end, 0);
	if (!str || !c)
		return (NULL);
	tab = ft_strsplit(str, c);
	if (!tab)
		return (NULL);
	while (tab[end])
			end++;
	ft_putstr("test001\n");
	end--;
	if (nb > end || end < 0)
	{
		ft_putstr("NULL002\n");
		return (NULL);
	}
	tmp_str = ft_strsub(tab[end - nb], 0, ft_strlen(tab[end - nb]));
	if (tmp_str)
	{
		printf("tmp =%s, nb =%d,\n", tmp_str, nb);
		ft_putstr("test003\n");
		return (tmp_str);
	}
	else
	{
		ft_putstr("NULL001\n");
		return (NULL);
	}
}

int 		go_ant(t_check *check, char *ant_name, char *next_cell)
{
	t_cells *tmp;

	tmp = check->start_list;
//	ft_putstr("test00\n");
	if (!ant_name || !next_cell)
	{
		ft_putstr("test01\n");
		return (0);
	}
	ft_putstr("test02\n");
	while (tmp)
	{
		ft_putstr("test03\n");
		if (!ft_strcmp(tmp->name, next_cell))
		{
			tmp->someone = ft_strdup(ant_name);
			break;
		}
		tmp = tmp->next;
	}
	ft_putstr("test04\n");
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
			if (tmp && go_ant(check, tmp->someone, tmp->route))
				free(tmp->someone);
			nb_arg++;
			if (!ft_strrnchr(good_roads[ligne], ' ', nb_arg))
				break;
			last_cell = ft_strdup(ft_strrnchr(good_roads[ligne], ' ', nb_arg));
		}
		nb_arg = 0;
		ligne++;
	}
	ft_putstr("test5\n");
	return (0);
}

int 		set_to_the_start(t_check *check, char **good_roads, t_ref *ref)
{
	t_cells *tmp;
	char 	**first_cell;

	FT_INIT(int, ligne, 0);
	tmp = check->start_list;
	while (good_roads[ligne])
	{
		first_cell = ft_strsplit(good_roads[ligne], ' ');
		tmp = find_cell(check, first_cell[0]);
		tmp->someone = ft_strdup(named(check, ref));
		if (!tmp->someone)
			return (0);
		ligne++;
	}
	return (0);
}

int 		moove_ants(t_check *check, t_ref *ref, char **good_roads)
{
	FT_INIT(int, nb_loops, 0);
	FT_INIT(int, last_ants, 0);
	last_ants = check->ants - ref->nb_ants_ref;
	while (last_ants)
	{
		last_ants = check->ants - ref->nb_ants_ref;
		in_min_ants(check, good_roads);
		if (last_ants < check->ants)
			set_to_the_start(check, good_roads, ref);
		print_list(check);
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
	print_list(check);
	moove_ants(check, &ref, good_roads);
	ft_putstr("All GOOD ROADS\n");
	print_simple_tab(good_roads);
	ft_putstr("END ALL GOOD ROAD\n");
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}