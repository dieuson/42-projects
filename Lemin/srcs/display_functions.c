/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:45:17 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 14:34:59 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void		print_simple_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab[ligne])
	{
		ft_putstr(tab[ligne]);
		ft_putstr("\n");
		ligne++;
	}
}

void		print_tab(char ***tab)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while (tab && tab[ligne])
	{
		while (tab[ligne][colonne])
		{
			ft_putstr(tab[ligne][colonne]);
			colonne++;
		}
		colonne = 0;
		ligne++;
		ft_putstr("\n");
	}
}

t_cells		*find_ant_nb(int nb, t_check *check)
{
	t_cells	*tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->someone && ft_atoi(ft_strchr(tmp->someone, 'L') + 1) == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		print_route(char **route, char *someone, char *name)
{
	char	*to_del;

	if (*route)
	{
		to_del = *route;
		*route = ft_strjoin(*route, " ");
		ft_strdel(&to_del);
		to_del = *route;
		*route = ft_strjoin(*route, someone);
		ft_strdel(&to_del);
	}
	else if (!*route)
		*route = ft_strdup(someone);
	to_del = *route;
	*route = ft_strjoin(*route, "-");
	ft_strdel(&to_del);
	*route = ft_strjoin(*route, name);
}
