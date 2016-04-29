/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_way_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:41:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:05:50 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char			*new_cell(char *road, t_check *check)
{
	char		*cell;
	char		*to_del;

	if (!ft_strrchr(road, ' '))
		return (NULL);
	cell = ft_strsub(road, 0, (ft_strlen(road)
	- (ft_strlen(ft_strrchr(road, ' ')))));
	if (!ft_strrchr(cell, ' '))
	{
		to_del = cell;
		cell = find_neighbor(cell, check->start_cell, check);
		ft_strdel(&to_del);
		return (cell);
	}
	to_del = cell;
	cell = ft_strsub(ft_strrchr(cell, ' '), 1,
	(ft_strlen(ft_strrchr(cell, ' ')) - 1));
	ft_strdel(&to_del);
	return (cell);
}

char			*first(char *road)
{
	char		*tmp;

	tmp = NULL;
	if (!road)
		return (NULL);
	if (ft_strchr(road, ' '))
		tmp = ft_strchr(road, ' ');
	else
		return (ft_strdup(road));
	return (ft_strsub(road, 0,
	(ft_strlen(road) - ft_strlen(ft_strchr(tmp, ' ')))));
}

int				nb_cells(char *road)
{
	FT_INIT(int, nb_arg, 0);
	while (road)
	{
		road = ft_strchr(road, ' ');
		if (road)
			road++;
		nb_arg++;
	}
	return (nb_arg);
}

int				bad_cell(t_check *check, char *road, char *cell)
{
	if (!check->posibilites)
		return (1);
	FT_INIT(int, ligne, 0);
	road = ft_strjoin(road, " ");
	FT_INIT(char*, to_del, road);
	road = ft_strjoin(road, cell);
	ft_strdel(&to_del);
	while (check->posibilites[ligne])
	{
		if (!ft_strcmp(road, check->posibilites[ligne]))
		{
			ft_strdel(&road);
			return (0);
		}
		ligne++;
	}
	ft_strdel(&road);
	if (!check->posibilites[ligne])
		return (-1);
	return (1);
}
