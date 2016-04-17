/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:32:02 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/07 18:29:38 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_cells		*create_cells(char *line)
{
	char 	*reste_tmp;
	t_cells *new;

	FT_INIT(long int, nb, 0);
	new = (t_cells *)malloc(sizeof(t_cells));
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
	new->next = NULL;
	new->neighbor = NULL;
	new->route = NULL;
	new->someone = NULL;
	return (new);
}

int			len_tab(char **tab)
{
	FT_INIT(int, i, 0);
	while (tab && tab[i])
		i++;
	return (i);
}

int 		add_neighbor(t_cells **first, t_cells **second)
{
	if ((*first)->neighbor && ft_strstr((*first)->neighbor, (*second)->name))
		return (0);
	if ((*first)->neighbor)
	{
		(*first)->neighbor = ft_strjoin((*first)->neighbor, " ");
		(*first)->neighbor = ft_strjoin((*first)->neighbor, (*second)->name);
	}
	else
		(*first)->neighbor = (*second)->name;
	if ((*second)->neighbor)
	{
		(*second)->neighbor = ft_strjoin((*second)->neighbor, " ");
		(*second)->neighbor = ft_strjoin((*second)->neighbor, (*first)->name);
	}
	else
		(*second)->neighbor = (*first)->name;
	return (1);
}

int 		link_cells(t_cells **cells, t_cells **second_list, char *line)
{
	char 	*name1;
	char 	*name2;

	FT_INIT(int, check, 0);
	FT_INIT(t_cells*, first, *second_list);
	FT_INIT(t_cells*, second, *second_list);
	while (*line == ' ' && *line)
		line++;
	FT_INIT(char *, reste, ft_strchr(line, '-'));
	name1 = ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	name2 = ft_strsub(reste, 1, (ft_strlen(reste) - 1));
	if (!ft_strcmp(name1, name2))
		return (0);
	while (first->next && ft_strcmp(first->name, name2) != 0)
		first = first->next;
	while (second->next && ft_strcmp(second->name, name1) != 0)
		second = second->next;
	if (!ft_strcmp(second->name, name1) && !ft_strcmp(first->name, name2))
		check = 2;
	if (check != 2)
		return (0);
	add_neighbor(&first, &second);
	if (cells)
		return (1);
	return (1);
}

int			start_end_min(char *line, t_check *check)
{
	if (ft_strstr("##start", line))
		return (check->start = 1);
	else if (ft_strstr("##end", line))
		return (check->end = 1);
	return (0);
}
