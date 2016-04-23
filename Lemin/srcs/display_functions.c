#include "../includes/lem-in.h"

void 		set_road(char **route, char **reste, t_cells *tmp, char *end_cell)
{
	if (tmp->route && end_cell && ft_strcmp(tmp->name, end_cell))
	{
		if (*route)
		{
			*route = ft_strjoin(*route, " ");
			*route = ft_strjoin(*route, tmp->someone);
		}
		else if (!*route)
			*route = ft_strdup(tmp->someone);
		*route = ft_strjoin(*route, "-");
		*route = ft_strjoin(*route, tmp->name);
	}
	if (tmp->route && end_cell && !ft_strcmp(tmp->route, end_cell))
	{
		if (*reste)
		{
			*reste = ft_strjoin(*reste, " ");
			*reste = ft_strjoin(*reste, tmp->someone);		
		}
		else
			*reste = ft_strdup(tmp->someone);
		*reste = ft_strjoin(*reste, "-");
		*reste = ft_strjoin(*reste, tmp->route);
	}
}

t_cells 	*find_and_nb(int nb, t_check *check)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->someone && ft_atoi(ft_strchr(tmp->someone, 'L') + 1) == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void 		print_ants_moves(t_check *check, char **good_roads)
{
	static char *reste = NULL;
	t_cells *tmp;

	FT_INIT(int, nb, 1);
	FT_INIT(char*, route, NULL);
	if (reste)
	{
		route = ft_strdup(reste);
		ft_memdel((void*)&reste);
	}
	while (nb <= check->ants)
	{
		tmp = find_and_nb(nb, check);
		if (tmp && !ft_len_tab(good_roads))
		{
			route = ft_strdup(tmp->someone);
			route = ft_strjoin(route, "-");
			route = ft_strjoin(route, tmp->name);
		}
		else if (tmp)
			set_road(&route, &reste, tmp, check->end_cell);
		nb++;
	}
	ft_putstr(route);
	ft_memdel((void*)&route);
}