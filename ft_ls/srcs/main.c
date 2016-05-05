/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:46:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:46:12 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void 		init_struct(t_store *store)
{
	store->start_list = NULL;
	store->flags = NULL;
	store->tab = NULL;
	store->len_tab = 5;
	store->argc = 0;
}

void 		free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
	free_simple_tab(&store->tab);
	ft_memdel((void**)&store->start_list);
}


void 		free_list(t_file **files)
{
	t_file 	*tmp;

	while ((*files))
	{
		tmp = (*files)->next;
		ft_strdel(&(*files)->path);
		ft_strdel(&(*files)->name);
		free_simple_tab(&(*files)->date);
		ft_strdel(&(*files)->rights);
		free((*files)->directories);
		ft_memdel((void**)&(*files));
		*files = tmp;
	}
}

int main (int argc, char **argv)
{
	t_file *files;
	t_store store;

	init_struct(&store);
	if (!detect_flags(&argv, argc, &store))
	{
		free_list(&store.start_list);
		free_struct(&store);
		return (0);
	}
	files = NULL;
	parse_args(argv, files, &store);
	print_data(&store);
	free_list(&(store.start_list));
	free_struct(&store);
	if (argc || argv || files)
		return (1);
	return (0);	
}