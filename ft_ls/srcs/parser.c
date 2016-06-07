/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:44:41 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/06 15:27:32 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*read_elements(t_store *store, int *nb_dir, DIR *rep)
{
	struct dirent *fd;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, start_new, NULL);
	while ((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		if (!new)
			MULTI(start_new, new, create_cells(fd->d_name, store, 0));
		else
		{
			new->next = create_cells(fd->d_name, store, 0);
			new = new->next;
		}
		store->len_print = compare_len(store->flags, new, store->len_print);
		if (store->flags && ft_strchr(store->flags, 'R')
		&& ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
			(*nb_dir) += ft_strchr(new->rights, 'd') ? 1 : 0;
	}
	return (start_new);
}

int			parse_args(char **argv, t_file *files, t_store *store)
{
	FT_INIT(t_file*, args, NULL);
	FT_INIT(int, verif, 0);
	store->len_print = create_int_tab(9);
	args = build_args_list(argv, store);
	FT_INIT(t_file*, start_args, args);
	while (args)
	{
		store->add_args = NULL;
		store->nb_blocks = 0;
		if (ft_strchr(args->rights, 'd'))
			store->nb_directories++;
		else
			store->nb_files++;
		verif = build_list(args->name, args->rights, store, &files);
		if (verif && store->add_args)
			args = cat_args_list(args, store);
		if (verif && args->next)
			store->len_print = create_int_tab(9);
		args = args->next;
	}
	if (store->start_list)
		print_data(store);
	if (start_args)
		free_list(start_args);
	return (1);
}
