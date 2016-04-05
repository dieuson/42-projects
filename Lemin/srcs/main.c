/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/05 13:29:02 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		init_struct(t_check *check, t_cells *cells)
{
	cells->next = NULL;
	cells = NULL;
	check->ants = 0;
	check->start = 0;
	check->end = 0;
	check->nb_args = 0;
	check->start_list = NULL;
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

t_cells 	*cells_creation(char *line)
{
	char 	*reste_tmp;
	t_cells *new;

	FT_INIT(long int, nb, 0);
	new = malloc(sizeof(t_cells*));
	while (*line && *line == ' ')
		line++;
	FT_INIT(char *, reste, ft_strchr(line, ' '));
	new->name =  ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	while (*reste && *reste == ' ')
		reste++;
	reste_tmp = reste;
	reste = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(ft_strchr(reste, ' '))));
	nb = ft_atoi(reste);
	new->pos_x =  nb <= 2147483647 && nb >= 0 ? nb : -1;
	reste_tmp = ft_strsub(reste_tmp, ft_strlen(reste), (ft_strlen(reste_tmp) - ft_strlen(reste)));
	while (*reste_tmp && *reste_tmp == ' ')
		reste_tmp++;
	nb = ft_atoi(reste_tmp);
	new->pos_y = nb <= 2147483647 && nb >= 0 ? nb : -1;
	free(reste);
	new->next = NULL;
	if (new->pos_x < 0 || new->pos_y < 0)
		new = NULL;
	return (new);
}

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		cells;

//	cells = NULL;
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
