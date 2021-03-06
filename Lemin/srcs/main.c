/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/24 11:29:42 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		detect_flags(t_check *check, int argc, char **argv)
{
	if (argc <= 1)
		return ;
	FT_INIT(int, line, 1);
	check->flags = ft_strdup("0000");
	while (argv[line])
	{
		if (ft_strchr(argv[line], '-'))
		{
			if (ft_strchr(argv[line], 'r'))
				(check->flags)[0] = 'r';
			if (ft_strchr(argv[line], 'c'))
				(check->flags)[1] = 'c';
			if (!ft_strstr(argv[line], "--name=") && ft_strchr(argv[line], 'm'))
				(check->flags)[2] = 'm';
			if (ft_strstr(argv[line], "--name="))
				if (ft_strlen(ft_strchr(argv[line], '=')) > 1)
					check->ant_name =
						ft_strdup((ft_strchr(argv[line], '=') + 1));
		}
		line++;
	}
}

static void		init_struct(t_check *check, int argc, char **argv)
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
	check->flags = NULL;
	check->ant_name = ft_strdup("L");
	detect_flags(check, argc, argv);
}

int				nb_ants(char *line, t_check *check, long int laps)
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

int				check_lemin(char *line, t_check *check, t_cells **cells)
{
	FT_INIT(int, nb_args, check_nb_args(line));
	if (!line)
		return (find_way(check));
	if (ft_strchr(line, '#') &&
	(ft_strcmp(line, "##start") && ft_strcmp(line, "##end")))
		return (1);
	if (!check->ants && nb_args == 1 && nb_ants(line, check, 1))
		return (1);
	if (check->ants && start_end_min(line, check))
		return (nb_args == 1 ? 1 : 0);
	if (check->ants && nb_args == 3
	&& (check->start || check->end || !(*cells)))
	{
		build_list(cells, check, line);
		if (check->start)
			check->start_cell = ft_strdup((*cells)->name);
		else if (check->end)
			check->end_cell = ft_strdup((*cells)->name);
		MULTI(check->start, check->end, 0);
		return (1);
	}
	if (check->ants && check->start_list
	&& nb_args <= 3 && !build_list(cells, check, line))
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	char		*line;
	t_check		check;
	t_cells		*cells;

	cells = NULL;
	line = NULL;
	FT_INIT(int, verif, 1);
	init_struct(&check, argc, argv);
	while (verif)
	{
		verif = get_next_line(0, &line);
		if (!check_lemin(line, &check, &cells))
		{
			ft_putstr("ERROR\n");
			free_chaine(&check.start_list, &check);
			return (-1);
		}
		if (verif)
		{
			ft_putendl(line);
			ft_memdel((void*)&line);
		}
	}
	free_chaine(&check.start_list, &check);
	return (1);
}
