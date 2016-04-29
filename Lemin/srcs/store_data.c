/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:01:17 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:07:33 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**store_good_ways(t_check *check)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(char**, tab, NULL);
	while (one_good_road(check, ligne))
	{
		tab = new_simple_tab(&tab);
		tab[ligne] = ft_strdup(one_good_road(check, ligne));
		tab[ligne + 1] = NULL;
		ligne++;
	}
	tab = short_way(tab);
	tab = del_over_road(tab, check);
	return (tab);
}

void		store_road(t_check *check, char *road)
{
	FT_INIT(int, ligne, 0);
	while (check->posibilites && check->posibilites[ligne])
		ligne++;
	check->posibilites = new_simple_tab(&check->posibilites);
	check->posibilites[ligne] = ft_strsub(road, 0, ft_strlen(road));
	check->posibilites[ligne + 1] = NULL;
}

int			*store_length_line(char **good_roads, int *line_length_min)
{
	FT_INIT(int, line, 0);
	FT_INIT(int*, line_length, NULL);
	while (good_roads[line])
		line++;
	line_length = (int*)malloc(sizeof(int) * line);
	line = 0;
	while (good_roads[line])
	{
		line_length[line] = nb_cells(good_roads[line]);
		line++;
	}
	line = 0;
	*line_length_min = line_length[0];
	while (line_length[line])
	{
		if (line_length[line] < *line_length_min)
		{
			*line_length_min = line_length[line];
			line = 0;
		}
		else
			line++;
	}
	return (line_length);
}
