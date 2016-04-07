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
	return (new);
}

int			len_tab(char **tab)
{
	FT_INIT(int, i, 0);
	while (tab && tab[i])
		i++;
	return (i);
}

char		**tab_copy(char ***tab)
{
	char	**fraiche_tab;

	FT_INIT(int, i, 0);
	FT_INIT(int, tab_len, len_tab(*tab));
	ft_putnbr(tab_len);
	fraiche_tab = malloc(sizeof(fraiche_tab) * (tab_len + 1));
	ft_putnbr(i);
	i = 0;
	while (tab && i < tab_len)
	{
		printf("\ncopy name = %s\n", *tab[i]);
//		fraiche_tab[i] = (char*)ft_memcpy((void*)fraiche_tab[i], (void*)(*tab[i]), ft_strlen(*tab[i]));
		fraiche_tab[i] = ft_strsub(*tab[i], 0, ft_strlen(*tab[i]));
		printf("\ntab name = %s\n", fraiche_tab[i]);
		i++;
	}
	return (fraiche_tab);
}
void		add_neighbor(t_cells **tmp, t_cells **start)
{
	ft_putstr("test1");
	FT_INIT(int, tab_len, len_tab((*tmp)->neighbor));
	FT_INIT(int, i, 0);
	ft_putstr("test");
//	ft_putstr("before copy\n");
	printf("\ntmp name = %s, start name = %s\n", (*tmp)->name, (*start)->name);
	ft_putstr("debut copy");
	(*tmp)->neighbor = tab_copy(&(*tmp)->neighbor);
	(*tmp)->neighbor[tab_len] = ft_strsub((*start)->name, 0, ft_strlen((*start)->name) + 1);
	ft_putstr("fin copy");
	(*tmp)->neighbor[tab_len + 1] = NULL;
	ft_putstr("test3");
//	ft_putstr("after copy\n");
	while ((*tmp)->neighbor[i])
	{
		ft_putnbr(i);
		printf("\nname = %s, pos_i = %d, val_case = %s\n", (*tmp)->name, i, (*tmp)->neighbor[i]);
		i++;
	}
	ft_putstr("END NEIGH\n");
//	(*tmp)->neighbor[tab_len - 1] = ft_strsub((*start)->name, 0, ft_strlen((*start)->name));
	if ((*start)->name)
		ft_putstr("FIRST LOOP\n\n");
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
