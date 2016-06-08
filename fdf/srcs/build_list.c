/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:54:59 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/08 12:32:11 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_node *create_cell(double x, double y, double value)
{
	FT_INIT(t_node *, new, NULL);
	new = (t_node*)malloc(sizeof(t_node));
	new->x = x;
	new->y = y;
	new->z = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node *build_list(char *line, double y, t_cloud *data)
{
	FT_INIT(t_node *, start_node, NULL);
	FT_INIT(t_node *, new, NULL);
	FT_INIT(char **, tmp, ft_strsplit(line, ' '));
	FT_INIT(double, x, 0);
	FT_INIT(int, i, 0);
	while (tmp && tmp[i])
	{
		if (!new)
			MULTI(start_node, new, create_cell(x, y, ft_atoi(tmp[i])));
		else
		{
			new->next = create_cell(x, y, ft_atoi(tmp[i]));
			new->prev = new;
			new = new->next;
		}
		i++;
		x++;
	}
	start_node = set_3d_pos(start_node, data);
	return (start_node);
}
