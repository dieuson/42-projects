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
	FT_INIT(int, nb_args, check_nb_args(line));
	if (!line)
		return (find_way(check));
	if (line[0] == '#' && line[1] != '#')
		return (1);
	if (!check->ants && nb_args == 1 && nb_ants(line, check, 1))
		return (1);
	if (check->ants && start_end_min(line, check))
		return (nb_args == 1 ? 1 : 0);
	if (check->ants && nb_args == 3 && (check->start || check->end))
	{
		build_list(cells, check, line);
		if (check->start)
			check->start_cell = ft_strdup((*cells)->name);
		else if (check->end)
			check->end_cell = ft_strdup((*cells)->name);
		check->start = 0;
		check->end = 0;
		return (1);
	}
	if (check->ants && check->start_list 
	&& nb_args <= 3 && !build_list(cells, check, line))
		return (0);
	return (1);
}

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		*cells;

	cells = NULL;
	line = NULL;
	FT_INIT(int, verif, 1);
	init_struct(&check);
	while (verif)
	{
		verif = get_next_line(0, &line);
		if (!check_lemin(line, &check, &cells))
		{
			ft_putstr("ERROR\n");
			free_struct(&check);
			free_chaine(&check.start_list);
			return (-1);
		}
		else if (verif)
		{
			ft_putendl(line);
			ft_memdel((void*)&line);
		}
	}
	free_struct(&check);
	free_chaine(&(check.start_list));
	return (1);
}
