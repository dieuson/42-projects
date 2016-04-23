/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/11 10:28:20 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		init_struct(t_check *check)
{
	check->ants = 0;
	check->start = 0;
	check->end = 0;
	check->links = 0;
	check->nb_args = 0;
	check->line_length_min = 0;
	check->line_length = NULL;
	check->start_cell = NULL;
	check->end_cell = NULL;
	check->start_list = NULL;
	check->posibilites = NULL;
	check->neighbor_tab = NULL;
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

int			check_lemin(char *line, t_check *check, t_cells **cells)
{
	FT_INIT(static int, laps, 0);
	FT_INIT(int, nb_args, check_nb_args(line));
	laps = check->ants ? laps : 0;
	if (!nb_args)
		return (find_way(check));
	if (line[0] == '#' && line[1] != '#')
		return (1);
	laps++;
	if (laps == 1 && nb_args == 1 && nb_ants(line, check, laps))
		return (1);
	if (laps > 1 && start_end_min(line, check))
	{
		if (nb_args == 1)
			return (laps = (laps == 2 ? 1 : laps));
		else
			return (0);
	}
	if (laps == 2 && nb_args == 3)
	{
		*cells = create_cells(line);
		check->start_list = *cells;
		if (check->start)
			check->start_cell = (*cells)->name;
		else if (check->end)
			check->end_cell = (*cells)->name;
		check->start = 0;
		check->end = 0;
		return (1);
	}
	if (laps > 2 && nb_args <= 3 && !build_list(cells, check, line))
		return (0);
	return (1);
}

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		*cells;
	int 		verif;
	
	cells = NULL;
	line = NULL;
	verif = 1;
	init_struct(&check);
	while (verif)
	{
		verif = get_next_line(0, &line);
		if (!check_lemin(line, &check, &cells))
		{
			ft_putstr("ERROR\n");
			return (-1);
		}
		else if (verif)
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (1);
}
