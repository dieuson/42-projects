#include "../includes/lem-in.h"

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

char 		*one_good_road(t_check *check, int nb_arg)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, tmp_nb_arg, 0);
	while (check->posibilites[ligne])
	{
		if (ft_strstr(check->posibilites[ligne],
		check->start_cell) &&
		ft_strstr(check->posibilites[ligne],
		check->end_cell))
		{
			if (tmp_nb_arg == nb_arg)
				return (check->posibilites[ligne]);
			tmp_nb_arg++;
		}
		ligne++;
	}
	return (NULL);
}

char  	**store_good_ways(char **tab, t_check *check)
{
	FT_INIT(int, ligne, 0);
	tab = (char **)malloc(sizeof(char *));
	tab[ligne] = one_good_road(check, ligne);
	while (tab[ligne])
	{
		ligne++;
		tab = new_simple_tab(tab);
		tab[ligne] = one_good_road(check, ligne);
		tab[ligne + 1] = NULL;
	}
	return (tab);
}


int 		distrib_moove_ant(t_check *check)
{
	t_ref	ref;
	t_cells *tmp;
	char 	**good_roads;
//	char 	*road;

	good_roads = NULL;
	tmp = check->start_list;
	ref.name_ref = "L";
	ref.nb_ants_ref = 1;
	ft_putstr("segfault\n");
	good_roads = store_good_ways(good_roads, check); 
	ft_putstr("segfault1\n");
	ft_putstr("All GOOD ROADS\n");
	print_simple_tab(good_roads);
	ft_putstr("END ALL GOOD ROAD\n");
	FT_INIT(int, stop, 0);
	while (stop < 2)
	{
	//	ft_putstr("test\n");
		tmp->someone = named(check, &ref);
		while (tmp)
		{
			tmp = tmp->next;
		}
	//	printf("tmp->someone =%s,\n", tmp->someone);
		tmp = check->start_list;
		stop++;
	}
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}