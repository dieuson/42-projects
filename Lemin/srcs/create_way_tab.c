#include "../includes/lem-in.h"

char 	*new_cell(char *road, t_check *check)
{
	char *cell_to_search;
	char *cell_to_del;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	cell_to_del = ft_strsub(ft_strrchr(road, ' '), 1, (ft_strlen(ft_strrchr(road, ' ')) - 1));
	road = ft_strsub(road, 0, (ft_strlen(road) - (ft_strlen(ft_strrchr(road, ' ')))));
	if (!ft_strrchr(road, ' '))
		return (find_neighbor(road, check->start_cell, check));
	cell_to_search = ft_strsub(ft_strrchr(road, ' '), 1, (ft_strlen(ft_strrchr(road, ' ')) - 1));
	while (check->neighbor_tab[ligne] && ft_strcmp(check->neighbor_tab[ligne][0], cell_to_search))
		ligne++;
	while (check->neighbor_tab[ligne][colonne] && ft_strcmp(check->neighbor_tab[ligne][colonne], cell_to_del))
		colonne++;
	while (check->neighbor_tab[ligne][colonne])
	{
		check->neighbor_tab[ligne][colonne] = check->neighbor_tab[ligne][colonne + 1];
		colonne++;
	}
	free(check->neighbor_tab[ligne][colonne - 1]);
	road = ft_strrchr(road, ' ');
	road++;
	return (cell_to_search);
}

void 		print_simple_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab[ligne])
	{
		ft_putstr(tab[ligne]);
		ft_putstr("\n");
		ligne++;
	}	
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
	return (fraiche_tab);
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

int 	bad_cell(t_check *check, char *cell)
{
	char *last_cell;

	if (!check->posibilites)
		return (1);
	FT_INIT(int, ligne, 0);
	while (check->posibilites[ligne])
	{

		last_cell= ft_strchr(check->posibilites[ligne], ' ');
		last_cell++;
		if (!ft_strcmp(cell, last_cell))
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
		&& bad_cell(check, check->neighbor_tab[ligne][colonne]))
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
	char *road;
	char *cell;

	FT_INIT(int, valid, 0);
	create_neighor_tab(check);
	cell = check->start_cell;
	road = cell;
	ft_putstr("FIrst neighbor_tab\n");
	print_tab(check->neighbor_tab);
	ft_putstr("END FIrst neighbor_tab\n");
	while (1)
	{
		cell = find_neighbor(road, cell, check);
		if (!cell || (ft_strstr(road, check->start_cell) && ft_strstr(road, check->end_cell)))
		{
			if (ft_strstr(road, check->start_cell) && ft_strstr(road, check->end_cell))
				valid++;
			store_road(check, road);
			cell = new_cell(road, check);
			road = ft_strsub(road, 0, (ft_strlen(road) - (ft_strlen(ft_strrchr(road, ' ')))));
			if (!cell)
				break;
		}
		else
		{
			road = ft_strjoin(road, " ");
			road = ft_strjoin(road, cell);
		}
	}
	ft_putstr("START All ROADS\n");
	print_simple_tab(check->posibilites);
	ft_putstr("END ALL ROAD\n");
	if (!valid)
		return (0);
	return (1);
}
