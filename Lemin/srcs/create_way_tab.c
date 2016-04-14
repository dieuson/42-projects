#include "../includes/lem-in.h"

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
	tab[ligne] = NULL;
	tab[ligne + 1] = NULL;
	short_way(tab);
	del_over_road(tab);
	return (tab);
}

void 	store_road(t_check *check, char *road)
{
	FT_INIT(int, ligne, 0);
	while (check->posibilites && check->posibilites[ligne])
		ligne++;
	check->posibilites = new_simple_tab(check->posibilites);
	check->posibilites[ligne] = ft_strsub(road, 0, ft_strlen(road));
	check->posibilites[ligne + 1] = NULL;
}

int 	bad_cell(t_check *check, char *road, char *cell)
{
	if (!check->posibilites)
		return (1);
	FT_INIT(int, ligne, 0);
	road = ft_strjoin(road, " ");
	road = ft_strjoin(road, cell);
	while (check->posibilites[ligne])
	{
		if (!ft_strcmp(road, check->posibilites[ligne]))
			return (0);
		ligne++;
	}
	if (!check->posibilites[ligne])
		return (-1);
	return (1);
}

char 	*find_neighbor(char *road, char *name, t_check *check)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	FT_INIT(char *, cell, NULL);
	while (check->neighbor_tab[ligne])
	{
		if (!ft_strcmp(name, check->neighbor_tab[ligne][0]))
			break;
		ligne++;
	}
	while (check->neighbor_tab[ligne][colonne])
	{
		if (!ft_strstr(road, check->neighbor_tab[ligne][colonne]) 
		&& bad_cell(check, road, check->neighbor_tab[ligne][colonne]))
				break;
		colonne++;
	}		
	if (!check->neighbor_tab[ligne][colonne])
		return (NULL);
	cell = ft_strsub(check->neighbor_tab[ligne][colonne], 0, ft_strlen(check->neighbor_tab[ligne][colonne]));
	return (cell);
}

int 	find_way(t_check *check)
{
	FT_INIT(int, valid, 0);
	FT_INIT(char *, cell, check->start_cell);
	FT_INIT(char *, road, cell);
	create_neighor_tab(check);
	while (cell)
	{
		cell = find_neighbor(road, cell, check);
		if (!cell || (ft_strstr(road, check->start_cell) && ft_strstr(road, check->end_cell)))
		{
			if (ft_strstr(road, check->start_cell) && ft_strstr(road, check->end_cell))
				valid++;
			store_road(check, road);
			cell = new_cell(road, check);
			road = ft_strsub(road, 0, (ft_strlen(road) - (ft_strlen(ft_strrchr(road, ' ')))));
		}
		else
		{
			road = ft_strjoin(road, " ");
			road = ft_strjoin(road, cell);
		}
	}
	if (!valid)
		return (0);
	return (distrib_moove_ant(check));
}
