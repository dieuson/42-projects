#include "../includes/lem-in.h"

char 	*new_cell(char *road, t_check *check)
{
	char *cell_to_search;

	road = ft_strsub(road, 0, (ft_strlen(road) - (ft_strlen(ft_strrchr(road, ' ')))));;
	if (!ft_strrchr(road, ' '))
		return (find_neighbor(road, check->start_cell, check));
	cell_to_search = ft_strsub(ft_strrchr(road, ' '), 1, (ft_strlen(ft_strrchr(road, ' ')) - 1));
	return (cell_to_search);
}

char 		**new_simple_tab(char **tab)
{
	char 	**fraiche_tab;

	FT_INIT(int, ligne, 0);
	if (!tab)
		return (fraiche_tab = (char **)malloc(sizeof(char *) * 1));
	while (tab[ligne])
		ligne++;
	fraiche_tab = (char **)malloc(sizeof(char *) * (ligne + 1));
	ligne = 0;
	while (tab[ligne])
	{
		fraiche_tab[ligne] = ft_strsub(tab[ligne], 0, ft_strlen(tab[ligne]));
		ligne++;
	}
	fraiche_tab[ligne] = NULL;
	return (fraiche_tab);
}

char 		*two_first(char *road)
{
	char 	*tmp;

	tmp = NULL;
	if (ft_strchr(road, ' '))
		tmp = ft_strchr(road, ' ');
	else
		return (NULL);
	return (ft_strsub(road, 0, (ft_strlen(road) - ft_strlen(ft_strchr(tmp, ' ')))));
}

int 		nb_cells(char *road)
{
	FT_INIT(int, nb_arg, 0);
	while (road)
	{
		road = ft_strchr(road, ' ');
		if (road)
			road++;
		nb_arg++;
	}
	return (nb_arg);
}

char 		**del_over_road(char **tab)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	while (tab[ligne2])
		ligne2++;
	FT_INIT(int, ref_end, ligne2 - 1);
	ligne2 = ref_end;
	while (ligne2 > 0 && tab[ligne2])
	{
		while (tab[ligne])
		{
			if ((tab[ligne] && tab[ligne2] && !ft_strncmp(tab[ligne],
			tab[ligne2], ft_strlen(two_first(tab[ligne]))) && 
			(nb_cells(tab[ligne2]) > nb_cells(tab[ligne]))))
			{
					free(tab[ligne2]);
					tab[ligne2] = NULL;
					ref_end--;
					ligne2 = ref_end;
			}
			ligne++;
		}
		ligne = 0;
		ligne2--;
	}
	return (tab);
}