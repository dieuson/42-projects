/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_simple_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:36:28 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:05:02 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		free_simple_tab(char ***tab)
{
	FT_INIT(int, colonne, 0);
	while ((*tab) && (*tab)[colonne])
	{
		free((*tab)[colonne]);
		(*tab)[colonne] = NULL;
		colonne++;
	}
	free(*tab);
	*tab = NULL;
}

char		**copy_simple_tab(char **src, char **dest)
{
	FT_INIT(int, colonne, 0);
	while (src && src[colonne])
	{
		dest[colonne] = ft_strdup(src[colonne]);
		colonne++;
	}
	dest[colonne] = NULL;
	return (dest);
}

char		**new_simple_tab(char ***tab)
{
	char	**fraiche_tab;

	FT_INIT(int, colonne, 0);
	if (!tab || !(*tab))
		return (fraiche_tab = (char **)malloc(sizeof(char *) * 2));
	while (*tab && (*tab)[colonne])
		colonne++;
	fraiche_tab = (char **)malloc(sizeof(char *) * (colonne + 2));
	fraiche_tab = copy_simple_tab(*tab, fraiche_tab);
	free_simple_tab(&(*tab));
	return (fraiche_tab);
}
