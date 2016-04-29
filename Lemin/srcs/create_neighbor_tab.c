/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 08:56:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 15:38:46 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char			*one_good_road(t_check *check, int nb_arg)
{
	char		*tmp;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, tmp_nb_arg, 0);
	while (check->posibilites[ligne])
	{
		if (ft_strstr(check->posibilites[ligne],
		check->start_cell) &&
		ft_strstr(check->posibilites[ligne],
		check->end_cell))
		{
			if (tmp_nb_arg == nb_arg)
			{
				tmp = ft_strchr(check->posibilites[ligne], ' ');
				tmp++;
				return (tmp);
			}
			tmp_nb_arg++;
		}
		ligne++;
	}
	return (NULL);
}

char			*find_args(char ***tab, char *name, int nb)
{
	FT_INIT(int, ligne, 0);
	if (!tab)
		return (NULL);
	while (tab[ligne] && ft_strcmp(tab[ligne][0], name))
		ligne++;
	if (!tab[ligne][nb])
		return (NULL);
	return (tab[ligne][nb]);
}

void			create_neighor_tab(t_check *check)
{
	t_cells		*tmp;
	char		*neighbor_ligne;
	char		*to_del;

	FT_INIT(int, ligne, 0);
	tmp = check->start_list;
	neighbor_ligne = NULL;
	check->neighbor_tab = NULL;
	while (tmp)
	{
		if (tmp->neighbor)
		{
			neighbor_ligne = ft_strjoin(tmp->name, " ");
			to_del = neighbor_ligne;
			neighbor_ligne = ft_strjoin(neighbor_ligne, tmp->neighbor);
			ft_strdel(&to_del);
			check->neighbor_tab = new_tab(&check->neighbor_tab);
			check->neighbor_tab[ligne] = ft_strsplit(neighbor_ligne, ' ');
			check->neighbor_tab[ligne + 1] = NULL;
			ft_strdel(&neighbor_ligne);
			ligne++;
		}
		tmp = tmp->next;
	}
}
