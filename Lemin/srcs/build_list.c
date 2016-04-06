/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:32:02 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/06 14:49:14 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_cells		*create_cells(char *line)
{
	char 	*reste_tmp;
	t_cells *new;
	t_neighbor *test;

	FT_INIT(long int, nb, 0);
	new = (t_cells *)malloc(sizeof(t_cells));
	test = (t_neighbor *)malloc(sizeof(t_neighbor));
	while (*line == ' ' && *line)
		line++;
	FT_INIT(char *, reste, ft_strchr(line, ' '));
	new->name =  ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	while (*reste == ' ' && *reste)
		reste++;
	reste_tmp = reste;
	reste = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(ft_strchr(reste, ' '))));
	nb = ft_atoi(reste);
	new->pos_x =  nb <= 2147483647 && nb >= 0 ? nb : -1;
	reste_tmp = ft_strsub(reste_tmp, ft_strlen(reste), (ft_strlen(reste_tmp) - ft_strlen(reste)));
	while (*reste_tmp == ' ' && *reste_tmp)
		reste_tmp++;
	nb = ft_atoi(reste_tmp);
	new->pos_y = nb <= 2147483647 && nb >= 0 ? nb : -1;
	free(reste);
	new->neighbor = test;
	new->neighbor->next = NULL;
	new->next = NULL;
	return (new);
}

void		add_neighbor(t_cells **tmp, t_cells **start)
{
	t_neighbor	*new;

	new = (t_neighbor *)malloc(sizeof(t_neighbor));
	new->next = NULL;
	new->name = (*tmp)->name;
	while ((*start)->neighbor->next)
		(*start)->neighbor = (*start)->neighbor->next;
	if ((*start)->neighbor->next)
	{
		(*start)->neighbor->next = new;
		(*start)->neighbor = (*start)->neighbor->next;
	}
	else
	{
		(*start)->neighbor->name = (*tmp)->name;
		(*start)->neighbor->first = (*start)->neighbor;
	}
	(*start)->neighbor->next = NULL;
	new->name = (*start)->name;
	if ((*tmp)->neighbor->next)
	{
		while ((*tmp)->neighbor->next)
			(*tmp)->neighbor = (*tmp)->neighbor->next;
		(*tmp)->neighbor->next = new;
		(*tmp)->neighbor = (*tmp)->neighbor->next;
	}
	else
	{
		(*tmp)->neighbor->name = (*start)->name;
		(*tmp)->neighbor->first = (*tmp)->neighbor;
	}
	(*tmp)->neighbor->next = NULL;
	(*tmp)->neighbor = (*tmp)->neighbor->first;
	(*start)->neighbor = (*start)->neighbor->first;
}

int 		link_cells(t_cells **cells, t_cells **start_list, char *line)
{
	char 	*name1;
	char 	*name2;

	FT_INIT(int, check, 0);
	FT_INIT(t_cells*, tmp, *start_list);
	FT_INIT(t_cells*, start, *start_list);
	while (*line == ' ' && *line)
		line++;
	FT_INIT(char *, reste, ft_strchr(line, '-'));
	name1 = ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	name2 = ft_strsub(reste, 1, (ft_strlen(reste) - 1));
	if (!ft_strcmp(name1, name2))
		return (0);
	while (tmp->next && ft_strcmp(tmp->name, name2) != 0)
		tmp = tmp->next;
	while (start->next && ft_strcmp(start->name, name1) != 0)
		start = start->next;
	if (!ft_strcmp(start->name, name1) && !ft_strcmp(tmp->name, name2))
		check = 2;
	if (check != 2)
		return (0);
	add_neighbor(&tmp, &start);
	if (cells)
		return (1);
	return (1);
}

int			start_end_min(char *line, t_check *check)
{
	if (ft_strstr("##start", line))
	{
		check->start = 1;
		return (1);
	}
	else if (ft_strstr("##end", line))
	{
		check->end = 1;
		return (1);
	}
	return (0);
}
