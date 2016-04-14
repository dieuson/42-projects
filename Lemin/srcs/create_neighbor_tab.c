/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 08:56:56 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/11 14:06:17 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char		*find_args(char ***tab, char *name, int nb)
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

void 		print_tab(char ***tab)
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

char 		***copy_tab(char ***src, char ***dest)
{
	FT_INIT(int, ligne, 0);
	while (src[ligne])
	{
		dest[ligne] = src[ligne];
		ligne++;
	}
	dest[ligne] = NULL;
	return (dest);
}

char 		***new_tab(char ***tab)
{
	char 	***fraiche_tab;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	if (!tab)
		return (fraiche_tab = (char ***)malloc(sizeof(char **) * 1));
	while (tab[ligne])
		ligne++;
	fraiche_tab = (char ***)malloc(sizeof(char **) * (ligne + 1));
	ligne = 0;
	while (tab[ligne])
	{
		while (tab[ligne][colonne])
			colonne++;
		fraiche_tab[ligne] = (char **)malloc(sizeof(char *) * (colonne + 1));
		colonne = 0;
		ligne++;
	}
	fraiche_tab = copy_tab(tab, fraiche_tab);
	return (fraiche_tab);
}

void 		create_neighor_tab(t_check *check)
{
	t_cells *tmp;
	char 	*neighbor_ligne;

	neighbor_ligne = NULL;
	FT_INIT(int, ligne, 0);
	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->neighbor)
		{
			neighbor_ligne = ft_strjoin(tmp->name, " ");
			neighbor_ligne = ft_strjoin(neighbor_ligne, tmp->neighbor);
			check->neighbor_tab = new_tab(check->neighbor_tab);
			check->neighbor_tab[ligne] = ft_strsplit(neighbor_ligne, ' ');
			check->neighbor_tab[ligne + 1] = NULL;
			ligne++;
		}
		tmp = tmp->next;
	}
	printf("all neighbor\n");
	print_tab(check->neighbor_tab);
	printf("FIN all neighbor\n");
}
