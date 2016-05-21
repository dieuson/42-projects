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
	store->add_args = NULL;
//	store->tab = NULL;
	store->len_tab = 5;
	store->argc = 0;
	store->nb_blocks = 0;
	store->path = "";
	store->len_print = 0;
	store->nb_blocks = 0;

}

int main (int argc, char **argv)
{
	t_file *files;
	t_store store;

	init_struct(&store);
	if (!detect_flags(&argv, argc, &store))
	{
		free_list(store.start_list);
		free_struct(&store);
		return (0);
	}
	files = NULL;
	parse_args(argv, files, &store);
	free_list(store.start_list);
	free_struct(&store);
//	print_data(&store);
//	free_list(&(store.start_list));
//	free_struct(&store);
//	if (argc || argv || files)
//		return (1);
	return (0);	
}