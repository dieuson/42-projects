#include "../includes/lem-in.h"

int			check_nb_args(char *line)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, nb_args, 0);
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_strchr(" ", line[i]) && line[i])
			nb_args++;
		while (!ft_strchr(" ", line[i]) && line[i])
			i++;
		while (ft_strchr(" ", line[i]) && line[i])
			i++;
		if (nb_args && !ft_strchr(" 0123456789", line[i]))
			return (0);
	}
	return (nb_args);
}

int 		verif_double(t_cells **cells, t_check *check)
{
	t_cells *tmp;
	t_cells *last_cell;

	FT_INIT(int, nb_args, 0);
	tmp = *cells;
	last_cell = *cells;
	while (nb_args < check->nb_args)
	{
		last_cell = last_cell->next;
		nb_args++;
	}
	nb_args = 0;
	while (nb_args < check->nb_args)
	{
		if (!ft_strcmp(tmp->name, last_cell->name))
			return (0);
		else if (tmp->pos_x == last_cell->pos_x && tmp->pos_y == last_cell->pos_y)
			return (0);
		tmp = tmp->next;
		nb_args++;
	}
	return (1);
}

int			build_list(t_cells **cells, t_check *check, char *line)
{
	FT_INIT(int, nb_args, check_nb_args(line));
	t_cells *tmp;

	tmp = check->start_list;
	if (nb_args == 3)
	{
		(*cells) = cells_creation(line);
		if (!(*cells))
			return (0);
	}
	if (nb_args == 3)
		if (!verif_double(cells, check))
			return (0);
	if (nb_args == 1)
	{
		if (!link_cells(cells, line))
			return (0);
		else
			ft_putstr("ok\n");
	}
	while (tmp->next)
	{
		printf("tmp->name =%s|, pos_x =%d| pos_y =%d|\n", tmp->name, tmp->pos_x, tmp->pos_y);
		tmp = tmp->next;
	}
	check->nb_args++;
	return (1);
}

int			check_lemin(char *line, t_check *check, t_cells *cells)
{
	t_cells *tmp;

	tmp = (check->start_list)	;
	FT_INIT(static int, laps, 0);
	FT_INIT(int, nb_args, check_nb_args(line));
	if (!nb_args)
		return (0);
	laps++;
	if (laps == 1 && nb_args == 1 && nb_ants(line, check, laps))
		return (1);
	if (laps == 2 && nb_args == 3)
	{
		cells = create_first_cell(line);
		check->start_list = cells;
		return (1);
	}
	while (tmp->next)
	{
		printf("totql tmp->name =%s|, pos_x =%d| pos_y =%d|\n", tmp->name, tmp->pos_x, tmp->pos_y);
		tmp = tmp->next;
	}
//	if (laps > 1 && start_end_min(line, check, cells))
//		return (1);
	if (laps > 2 && nb_args == 3)
	{
//		printf("tmp->name =%s|, pos_x =%d| pos_y =%d|\n", tmp->name, tmp->pos_x, tmp->pos_y);
		cells->next = create_first_cell(line);
		cells = cells->next;
//		printf("tmp->name =%s|, pos_x =%d| pos_y =%d|\n", tmp->name, tmp->pos_x, tmp->pos_y);
		return (1);
	}
//	if (laps > 2 && nb_args <= 3)
//		return (build_list(&cells, check, line));
	return (0);
}
