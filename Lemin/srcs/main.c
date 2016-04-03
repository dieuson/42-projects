/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/01 13:45:29 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		init_struct(t_check *check, t_cells *cells)
{
	check->ants = 0;
	check->start = 0;
	check->end = 0;
	check->nb_args = 0;
	cells->next = NULL;
	cells->name = NULL;
	cells->someone = 0;
	cells->pos_x = 0;
	cells->pos_y = 0;
	cells->neighbor->next = NULL;
	cells->neighbor->name = NULL;
	cells->neighbor->someone = 0;
	cells->neighbor->pos_x = 0;
	cells->neighbor->pos_y = 0;
}

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

int			nb_ants(char *line, t_check *check, long int laps)
{
	FT_INIT(int, i, 0);
	FT_INIT(long int, nb, 0);
	while (line[i])
	{
		if (laps == 1 && !ft_strchr("0123456789", line[i]))
			return (0);
		i++;
	}
	if (laps == 1)
	{
		nb = ft_atoi(line);
		if (nb <= 0 || nb > 2147483647)
			return (0);
		check->ants = nb;
	}
	return (1);
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

void 		cells_creation(t_cells **cells, char *line)
{
	t_cells *tmp;
	char 	*reste;
	char 	*reste_tmp;
	FT_INIT(long int, nb, 0);

	tmp = *cells;
	while (tmp->next && line)
		tmp = tmp->next;
	reste = ft_strchr(line, ' ');
	tmp->name =  ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	while (*reste == ' ' && *reste)
		reste++;
	reste_tmp = reste;
	reste = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(ft_strchr(reste, ' '))));
	nb = ft_atoi(reste);
	tmp->pos_x =  nb <= 2147483647 && nb >= 0 ? nb : -1;
	reste_tmp = ft_strsub(reste_tmp, ft_strlen(reste), (ft_strlen(reste_tmp) - ft_strlen(reste)));
	while (*reste_tmp == ' ' && *reste_tmp)
		reste_tmp++;
	nb = ft_atoi(reste_tmp);
	tmp->pos_y = nb <= 2147483647 && nb >= 0 ? nb : -1;
	free(reste);
	tmp->next =  malloc(sizeof(t_cells));
}

int			build_list(t_cells **cells, t_check *check, char *line)
{
	FT_INIT(int, nb_args, check_nb_args(line));
	t_cells *tmp;

	if (nb_args == 3)
		cells_creation(cells, line);
	tmp = *cells;
	nb_args = 0;
	while (nb_args < check->nb_args)
	{
		tmp = tmp->next;
		nb_args++;
	}
	printf("name = %s pos_x = %d, pos_y = %d\n", tmp->name, tmp->pos_x, tmp->pos_y);
	if (tmp->pos_x < 0 || tmp->pos_y < 0)
		return (0);
	if (!verif_double(cells, check))
		return (0);
	check->nb_args++;
	return (1);
}

int			start_end_min(char *line, t_check *check, t_cells *cells, int laps)
{
	if (laps && !ft_strcmp("##start", line))
		return (check->start = 1);
	if (laps && !ft_strcmp("##end", line))
		return (check->end = 1);
	if (check->start && laps)
	{
		check->start_cell = line;
		check->start = 0;
		return (build_list(&cells, check, line));
	}
	else if (check->end && laps)
	{
		check->end_cell = line;
		check->end = 0;
		return (build_list(&cells, check, line));
	}
	return (0);
}

int			check_lemin(char *line, t_check *check, t_cells *cells)
{
	FT_INIT(static int, laps, 0);
	FT_INIT(int, nb_args, check_nb_args(line));
	if (!nb_args)
		return (0);
	laps++;
	if (laps == 1 && nb_args == 1 && nb_ants(line, check, laps))
		return (1);
	if (laps > 1 && start_end_min(line, check, cells, laps))
		return (1);
	if (laps > 1 && nb_args <= 3)
		return (build_list(&cells, check, line));
	return (0);
}

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		cells;

	init_struct(&check, &cells);
	while (get_next_line(0, &line))
	{
		if (!line || !check_lemin(line, &check, &cells))
		{
			ft_putstr("ERROR\n");
			return (-1);
		}
		else
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (0);
}
