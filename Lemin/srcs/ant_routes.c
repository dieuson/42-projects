/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_routes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:26:29 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:04:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**short_way(char **tab)
{
	FT_INIT(char *, tmp, NULL);
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	while (tab[ligne])
	{
		while (tab[ligne2])
		{
			if (nb_cells(tab[ligne2]) < nb_cells(tab[ligne]))
			{
				tmp = tab[ligne];
				tab[ligne] = tab[ligne2];
				tab[ligne2] = tmp;
			}
			ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
	return (tab);
}

void		put_route(t_check *check, char **good_roads)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(char*, cell, NULL);
	FT_INIT(char*, first_cell, NULL);
	FT_INIT(t_cells*, tmp, check->start_list);
	while (good_roads[ligne])
	{
		cell = good_roads[ligne];
		while (tmp)
		{
			if (!(first_cell = first(cell)) || !ft_strchr(cell, ' '))
				break ;
			if (!ft_strcmp(first_cell, tmp->name))
			{
				cell = ft_strchr(cell, ' ') + 1;
				tmp->route = first(cell);
				tmp = check->start_list;
			}
			ft_strdel(&first_cell);
			tmp = tmp->next;
		}
		ft_strdel(&first_cell);
		ligne++;
		tmp = check->start_list;
	}
	ft_strdel(&first_cell);
}

t_cells		*find_cell(t_check *check, char *cell_name)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, cell_name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char		*ft_strrnchr(char *str, int c, int nb)
{
	char	**tab;
	char	*tmp_str;

	FT_INIT(int, end, 0);
	if (!str || !c)
		return (NULL);
	tab = ft_strsplit(str, c);
	if (!tab)
		return (NULL);
	while (tab[end])
		end++;
	end--;
	if (nb > end || end < 0)
	{
		free_simple_tab(&tab);
		return (NULL);
	}
	tmp_str = ft_strdup(tab[end - nb]);
	free_simple_tab(&tab);
	if (tmp_str)
		return (tmp_str);
	else
		return (NULL);
}

int			ft_len_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab && tab[ligne])
		ligne++;
	ligne--;
	if (!ligne)
		if (!ft_strchr(tab[ligne], ' '))
			return (0);
	ligne++;
	return (ligne);
}
