#include "../includes/lem-in.h"

void 		free_chaine(t_cells **cells)
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
}

void 		free_struct(t_check *check)
{
	ft_strdel(&check->start_cell);
	ft_strdel(&check->end_cell);
	free_tab(&check->neighbor_tab);
	free_simple_tab(&(check->posibilites));
	free_simple_int_tab(&check->line_length);
}