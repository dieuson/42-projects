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
	ft_putstr("All GOOD ROADS\n");
	print_simple_tab(good_roads);
	ft_putstr("END ALL GOOD ROAD\n");
	FT_INIT(int, stop, 0);
	while (stop < 2)
	{
	//	ft_putstr("test\n");
		tmp->someone = ft_strsub(named(check, &ref), 0, ft_strlen(named(check, &ref)));
	//	ft_putstr("test1\n");
		while (tmp->next)
		{
	//		ft_putstr("test2\n");
			tmp = tmp->next;
	//		ft_putstr("test3\n");
		}
	//	printf("tmp->someone =%s,\n", tmp->someone);
		tmp = check->start_list;
		stop++;
	}
	if (ref.nb_ants_ref || tmp)
		return (1);
	return (0);
}