/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:15:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/16 14:15:06 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
}

void 			free_int_tab(int **tab, int nb_lines)
{
	int 	colonne;

	colonne = 0;
	if (!(*tab) || !nb_lines)
		return ;
	while (colonne < nb_lines)
	{
	//	free(tab[colonne]);
	//	(tab)[colonne] = 0;
		colonne++;
	}
//	free(tab);
//	tab = 0;
}

void			free_list(t_file *files)
{
	FT_INIT(t_file*, tmp, files);
	while (files)
	{
		tmp = (files)->next;
		ft_strdel(&(files)->path);
		ft_strdel(&(files)->absolute_path);
		ft_strdel(&(files)->name);
		free_simple_tab(&((files)->date));
		free(files->date);
		ft_strdel(&(files)->rights);
		if (files->private)
			ft_strdel(&(files)->private);
		files->size = 0;
		files->link = 0;
		files->directories = 0;
		files->nb_blocks = 0;
		if (files)
			ft_memdel((void**)&(files));
		files = tmp;
	}
	files = NULL;
}
