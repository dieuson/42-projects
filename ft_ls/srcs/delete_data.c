/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:15:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/07 09:55:24 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
}

void			free_int_tab(int **tab, int nb_lines)
{
	if (!(*tab) || !nb_lines)
		return ;
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
