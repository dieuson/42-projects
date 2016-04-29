/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:32:02 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 15:42:24 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		set_as_none(t_cells **new, char **reste, char **name)
{
	(*new)->next = NULL;
	(*new)->neighbor = NULL;
	(*new)->route = NULL;
	(*new)->someone = NULL;
	ft_strdel(&(*reste));
	ft_strdel(&(*name));
}

t_cells		*create_cells(char *line)
{
	FT_INIT(t_cells *, new, (t_cells *)malloc(sizeof(t_cells)));
	FT_INIT(long int, nb, 0);
	while (line && *line == ' ')
		line++;
	FT_INIT(char *, reste, ft_strchr(line, ' '));
	new->name = ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	while (reste && *reste == ' ')
		reste++;
	FT_INIT(char *, reste_tmp, ft_strdup(reste));
	FT_INIT(char *, name, reste_tmp);
	reste = ft_strsub(reste, 0, (ft_strlen(reste)
	- ft_strlen(ft_strchr(reste, ' '))));
	nb = ft_atoi(reste);
	new->pos_x = nb <= 2147483647 && nb >= 0 ? nb : -1;
	reste_tmp = ft_strsub(reste_tmp, ft_strlen(reste),
	(ft_strlen(reste_tmp) - ft_strlen(reste)));
	ft_strdel(&name);
	name = reste_tmp;
	while (reste_tmp && *reste_tmp == ' ')
		reste_tmp++;
	nb = ft_atoi(reste_tmp);
	new->pos_y = nb <= 2147483647 && nb >= 0 ? nb : -1;
	set_as_none(&new, &reste, &name);
	return (new);
}

int			add_neighbor(t_cells **first, t_cells **second)
{
	if ((*first)->neighbor && ft_strstr((*first)->neighbor, (*second)->name))
		return (0);
	FT_INIT(char*, tmp, (*first)->neighbor);
	if ((*first)->neighbor)
	{
		(*first)->neighbor = ft_strjoin((*first)->neighbor, " ");
		ft_strdel(&tmp);
		tmp = (*first)->neighbor;
		(*first)->neighbor = ft_strjoin((*first)->neighbor, (*second)->name);
		ft_strdel(&tmp);
	}
	else if (!(*first)->neighbor)
		(*first)->neighbor = ft_strdup((*second)->name);
	if ((*second)->neighbor)
	{
		tmp = (*second)->neighbor;
		(*second)->neighbor = ft_strjoin((*second)->neighbor, " ");
		ft_strdel(&tmp);
		tmp = (*second)->neighbor;
		(*second)->neighbor = ft_strjoin((*second)->neighbor, (*first)->name);
		ft_strdel(&tmp);
	}
	else if (!(*second)->neighbor)
		(*second)->neighbor = ft_strdup((*first)->name);
	return (1);
}

int			link_cells(t_cells *start, t_check *check, char *line)
{
	FT_INIT(int, checkin, 0);
	FT_INIT(t_cells*, first, start);
	FT_INIT(t_cells*, second, start);
	while (*line && *line == ' ')
		line++;
	FT_INIT(char *, reste, ft_strchr(line, '-'));
	FT_INIT(char*, name1, ft_strsub(line, 0,
	(ft_strlen(line) - ft_strlen(reste))));
	FT_INIT(char*, name2, ft_strsub(reste, 1, (ft_strlen(reste) - 1)));
	if (!ft_strcmp(name1, name2))
		return (0);
	while (first->next && ft_strcmp(first->name, name2))
		first = first->next;
	while (second->next && ft_strcmp(second->name, name1))
		second = second->next;
	if (!ft_strcmp(second->name, name1) && !ft_strcmp(first->name, name2))
		checkin = 2;
	ft_strdel(&name1);
	ft_strdel(&name2);
	if (checkin != 2)
		return (0);
	add_neighbor(&first, &second);
	check->links = 1;
	return (1);
}

int			build_list(t_cells **cells, t_check *check, char *line)
{
	FT_INIT(int, nb_args, check_nb_args(line));
	if (*cells && nb_args == 3)
	{
		(*cells)->next = create_cells(line);
		*cells = (*cells)->next;
		if (!verif_double(cells, check))
			return (0);
	}
	else if (!(*cells) && nb_args == 3)
		MULTI(check->start_list, (*cells), create_cells(line));
	if (nb_args == 1 && (!check->start_cell
	|| !check->end_cell || !link_cells(check->start_list, check, line)))
		return (0);
	check->nb_args++;
	return (1);
}
