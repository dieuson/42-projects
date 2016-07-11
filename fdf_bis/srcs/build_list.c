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

t_node  	*create_cell(double x, double y, double z, t_cloud *data)
{
	t_node* new;

	new = (t_node*)malloc(sizeof(t_node));
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	new = get_2d_pos(new, data);
	if (!data)
		return (new);
	return (new);
}

t_node		*build_list(double pos_y, t_cloud *data, char *line)
{
	FT_INIT(int, x, 0);
	FT_INIT(char **, tab, ft_strsplit(line, ' '));
	FT_INIT(t_node*, new, NULL);
	FT_INIT(t_node*, head, NULL);
	while (tab && tab[x])
	{
		if (!head)
			MULTI(head, new, create_cell(x, pos_y, ft_atoi(tab[x]), data));
		else
		{
			new->next = create_cell(x, pos_y, ft_atoi(tab[x]), data);
			new = new->next;
		}
		x++;
	}
	return (head);
}