/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_over_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:42:57 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 10:44:35 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char		**del_tab_line(char **tab, int line)
{
	while (tab[line])
	{
		tab[line] = tab[line + 1];
		line++;
	}
	if (tab[line - 1])
		ft_memdel((void*)tab[line - 1]);
	return (tab);
}

int			verif_deleted_line(char *line, char *line2, t_check *check)
{
	FT_INIT(char*, last_cell, NULL);
	FT_INIT(int, nb_arg, 0);
	last_cell = ft_strrnchr(line, ' ', nb_arg);
	while (last_cell)
	{
		if (last_cell && ft_strcmp(last_cell, check->end_cell)
		&& ft_strstr(line2, last_cell))
		{
			ft_strdel(&last_cell);
			return (1);
		}
		nb_arg++;
		ft_strdel(&last_cell);
		last_cell = ft_strrnchr(line, ' ', nb_arg);
		if (!last_cell)
			break ;
		ft_memdel((void*)&last_cell);
	}
	return (0);
}

char		**del_second_par(char **tab, t_check *check)
{
	FT_INIT(int, line, 0);
	FT_INIT(char*, to_del, NULL);
	FT_INIT(int, ref, ft_len_tab(tab) - 1);
	FT_INIT(int, line2, ref);
	while (line2 > 0 && tab[line2])
	{
		while (tab[line] && tab[line2])
		{
			to_del = ft_strrnchr(tab[line], ' ', 0);
			if (!to_del)
				break ;
			ft_strdel(&to_del);
			if (ft_strcmp(tab[line], tab[line2]) &&
			verif_deleted_line(tab[line], tab[line2], check))
			{
				del_tab_line(tab, line2);
				MULTI(line2, ref, ref - 1);
			}
			line++;
		}
		line2 = line > 0 ? (line2 - 1) : ref;
		line = 0;
	}
	return (tab);
}

int			compare_cells(int line, int line2, char **tab, char *end_cell)
{
	char	*tab1;
	char	*tab2;
	int		verif;

	verif = 0;
	tab1 = first(tab[line]);
	tab2 = first(tab[line2]);
	if ((ft_strcmp(tab1, end_cell) && ft_strcmp(tab2, end_cell)
	&& ft_strcmp(tab2, tab1) && ft_strstr(tab[line2], tab1)) || (line2 != line
	&& !ft_strcmp(tab2, tab1)))
		verif++;
	ft_strdel(&tab1);
	ft_strdel(&tab2);
	if (verif)
		return (1);
	return (0);
}

char		**del_over_road(char **tab, t_check *check)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, ref, ft_len_tab(tab) - 1);
	FT_INIT(int, line2, ref);
	while (line2 > 0 && tab[line2])
	{
		while (tab[line2] && tab[line])
		{
			if (compare_cells(line, line2, tab, check->end_cell))
			{
				del_tab_line(tab, line2);
				MULTI(line2, ref, ref - 1);
				line = 0;
				break ;
			}
			else
				line++;
		}
		line2 = line > 0 ? (line2 - 1) : ref;
		line = 0;
	}
	return (del_second_par(tab, check));
}
