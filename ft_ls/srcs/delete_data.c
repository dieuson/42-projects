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
	free(&store->start_list);
}

void			free_list(t_file *files)
{
	FT_INIT(t_file*, tmp, NULL);
	while ((files))
	{
		tmp = (files)->next;
		ft_strdel(&(files)->path);
		ft_strdel(&(files)->name);
		free_simple_tab(&(files)->date);
		free(files->date);
		ft_strdel(&(files)->rights);
		ft_strdel(&(files)->absolute_path);
		ft_memdel((void**)&(files));
		files = tmp;
	}
	files = NULL;
}
