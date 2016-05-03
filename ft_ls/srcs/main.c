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
	store->flags = "";
}

int main (int argc, char **argv)
{
	t_file *files;
	t_store store;
	struct dirent* fichierLu;

	init_struct(&store);
	if (!detect_flags(&argv, argc, &store))
		return (0);
	fichierLu = NULL;
	files = NULL;
	if (argc > 1)
		parse_dir(fichierLu, argv[1], files, &store);
	else
		parse_dir(fichierLu, ".", files, &store);
	if (argc || argv)
		return (1);
	return (0);	
}