#include "../includes/lem-in.h"

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

int 		ft_len_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab && tab[ligne])
		ligne++;
	ligne--;
	if (!ligne)
		if (!ft_strchr(tab[ligne], ' '))
				return (0);
	ligne++;
	return (ligne);
}