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
	cells->next = NULL;
	cells->name = NULL;
	cells->someone = 0;
	cells->neighbor->next = NULL;
	cells->neighbour->name = NULL;
	cells->neighbour->someone = 0;
}

int			check_nb_args(char *line)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, nb_args, 0);
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
	if (nb_args == 3)
		return (1);
	else
		return (0);
}

int			nb_ants(char *line, t_check *check, long int laps)
{
	FT_INIT(int, i, 0);
	FT_INIT(long int, nb, 0);
	while (line[i])
	{
		if (!laps && !ft_strchr("0123456789", line[i]))
			return (0);
		i++;
	}
	if (!laps)
	{
		nb = ft_atoi(line);
		if (nb < -2147483648 || nb > 2147483647 || (nb < 0 && !laps))
			return (0);
		check->ants = nb;
	}
	return (1);
}

int			start_end_min(char *line, t_check *check, long int laps)
{
	if (laps && !ft_strcmp("##start", line))
		return (check->start = 1);
	if (laps && !ft_strcmp("##end", line))
		return (check->end = 1);
	if (check->start && laps)
	{
		check->start_cell = line;
		check->start = 0;
	}
	if (check->end && laps)
	{
		check->end_cell = line;
		check->end = 0;
	}
	return (0);
}

int			build_list(t_cells *cells)
{

	ft_lstadd_bottom(&cells, cells);
}
int			check_lemin(char *line, t_check *check, t_cells *cells)
{
	FT_INIT(static long int, laps, 0);
	if (start_end_min(line, check, laps))
		return (1);
	if (laps && !check_nb_args(line))
		return (0);
	if (!nb_ants(line, check, laps))
		return (0);
	build_list(cells);
	laps++;
	return (1);
}

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		cells;

	init_struct(&check, &cells);
	while (get_next_line(0, &line))
	{
		if (!line || !check_lemin(line, &check))
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
