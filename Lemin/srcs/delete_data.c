/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:44:53 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 15:41:46 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		free_chaine(t_cells **cells, t_check *check)
{
	while (*cells && cells)
	{
		if (*cells && (*cells)->name)
			ft_strdel(&(*cells)->name);
		if ((*cells)->someone)
			ft_strdel(&(*cells)->someone);
		if (*cells && (*cells)->route)
			ft_strdel(&(*cells)->route);
		if ((*cells)->neighbor)
			ft_strdel(&(*cells)->neighbor);
		free(*cells);
		*cells = (*cells)->next;
	}
	*cells = NULL;
	ft_strdel(&check->start_cell);
	ft_strdel(&check->end_cell);
	free_tab(&check->neighbor_tab);
	free_simple_tab(&(check->posibilites));
}
