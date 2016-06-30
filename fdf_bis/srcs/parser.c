/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:57:50 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/28 14:42:20 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_liste(t_node *list)
{
	while (list)
	{
		printf("x = %f, y =%f, z =%f,\n", list->x, list->y, list->z);
		list = list->next;
	}
}

int			parser(char **argv, t_cloud *data)
{
	FT_INIT(char *, line, NULL);
	FT_INIT(double, pos_y, 0);
	FT_INIT(int, fd, 0);
	FT_INIT(int, verif, 1);
	FT_INIT(t_node*, list, NULL);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_fdf("Error open file");
	while (verif)
	{
		if (!(verif = get_next_line(fd, &line)))
			break ;
		if (!list)
			MULTI(data->start_node, list, build_list(pos_y, data, line));
		else
		{
			list->next  = build_list(pos_y, data, line);
			list = list->next;
		}
		while (list && list->next)
			list = list->next;
		if (line)
			ft_strdel(&line);
		pos_y++;
	}
	return (0);
}
