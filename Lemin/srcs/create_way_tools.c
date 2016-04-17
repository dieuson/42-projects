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

char 		*first(char *road)
{
	char 	*tmp;

	tmp = NULL;
	if (!road)
		return (NULL);
	if (ft_strchr(road, ' '))
		tmp = ft_strchr(road, ' ');
	else
		return (road);
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

char 		**del_tab_line(char **tab, int line)
{
	while (tab[line])
	{
		tab[line] = tab[line + 1];
		line++;
	}
	if (tab[line - 1])
	{
		free(tab[line - 1]);
		tab[line - 1] = NULL;
	}
	return (tab);
}

char 		**del_second_par(char **tab, t_check *check)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, line2, 0);
	FT_INIT(int, ref, 0);
	while (tab[line2])
		line2++;
	line2--;
	if (check->ants)
		ref = line2;
	while (line2 > 0 && tab[line2])
	{
		while (tab[line2] && tab[line])
		{
			if ((ft_strcmp(first(tab[line2]), first(tab[line]))
			&& ft_strstr(tab[line2], first(tab[line]))) || (line2 != line 
			&& !ft_strcmp(first(tab[line2]), first(tab[line]))))
			{
				del_tab_line(tab, line2);
				line = 0;
				ref--;
				line2 = ref;
				break;
			}
			else
				line++;
		}
		line2 = line > 0 ? (line2 - 1) : ref;
		line = 0;
	}
	return (tab);
}

char 		**del_over_road(char **tab, t_check *check)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	while (tab[ligne2])
		ligne2++;
	FT_INIT(int, ref_end, ligne2 - 1);
	ligne2 = ref_end;
	if (check->ants)
		ref_end = ligne2;
	while (ligne2 > 0 && tab[ligne2])
	{
		while (tab[ligne])
		{
			if ((tab[ligne] && tab[ligne2] && !ft_strncmp(tab[ligne],
			tab[ligne2], ft_strlen(first(tab[ligne]))) && 
			(nb_cells(tab[ligne2]) > nb_cells(tab[ligne]))))
			{

					del_tab_line(tab, ligne2);
					ref_end--;
					ligne2 = ref_end;
			}
			ligne++;
		}
		ligne = 0;
		ligne2--;
	}
	del_second_par(tab, check);
	return (tab);
}