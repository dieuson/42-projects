/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/07 10:09:09 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		init_struct(t_check *check)
{
	check->ants = 0;
	check->start = 0;
	check->end = 0;
	check->nb_args = 0;
	check->start_list = NULL;
	check->posibilites = NULL;
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

int			main(void)
{
	char 		*line;
	t_check		check;
	t_cells		*cells;

	cells = NULL;
	init_struct(&check);
	while (get_next_line(0, &line))
	{
		if (!check_lemin(line, &check, &cells))
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