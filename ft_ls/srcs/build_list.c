/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:13:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/16 14:13:41 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
/*
t_file				*create_simple_cells(char *name, t_store *store)
{
	struct stat		infos;

	lstat(name, &infos);
//	ft_printf("ELSE build_list\n");
//	ft_putendl("TEST1");
//	ft_printf("lstat=%d, \n", );
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(name);
	new->path = ft_strrchr(name, '/') ? ft_strdup(ft_strrchr(name, '/') + 1) : ft_strdup(name);
	new->absolute_path = ft_strdup(name);
	if (store->flags && (ft_strchr(store->flags, 'l') || ft_strchr(store->flags, 'g')))
	{
		new->owner = get_owner(infos);
		new->owner_grp = get_owner_grp(infos);
		if (!(new->date = get_date(infos, 1)))
			(store->flags)[0] = '0';
	}
//	ft_putendl("TEST2");
//	ft_putendl("TEST3");
	new->time_estamp = store->flags && !ft_strchr(store->flags, 't') && 
	ft_strchr(store->flags, 'u') ? infos.st_atimespec.tv_sec : get_time_estamp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->nb_blocks = infos.st_blocks;
	new->rights = get_rights(infos);
	new->private = NULL;
	if (store->flags && ft_strchr(store->flags, 'l') && ft_strchr(new->rights, 'l'))
		new->private = ft_strchr(new->name, '/') ? ft_strdup(ft_strrchr(new->name, '/') + 1) : ft_strdup(new->name);
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
//	ft_putendl("TEST4");
	new->display = 0;
	new->next = NULL;
	return (new);
}*/

t_file				*create_cells(char *name, t_store *store, int type)
{
	struct stat		infos;
	char *path;

	FT_INIT(char *, flags, store->flags);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	path = !type ? ft_strjoin(store->path, name) : ft_strdup(name);
	lstat(path, &infos);
	new->name = ft_strdup(name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
	new = get_owners(infos, new);
//	new->owner = get_owner(infos);
//	new->owner_grp = get_owner_grp(infos);
	if (!(new->date = get_date(infos, flags)))
		(flags)[0] = '0';
	new->rights = get_rights(infos);
	new->private = NULL;
	if (flags && ft_strchr(flags, 'l') && ft_strchr(new->rights, 'l'))
		new->private = ft_strrchr(new->name, '/') ? 
			ft_strdup(ft_strrchr(new->name, '/') + 1) : ft_strdup(new->name);
	new = get_integers_data(infos, new, flags);
	new->next = NULL;
	ft_strdel(&path);
	return (new);
}

static t_file 		*build_args_cells(char **argv, t_store *store, int type)
{
	FT_INIT(int, line, 1);
	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, tmp, create_cells(argv[0], store, 1));
	FT_INIT(t_file*, start_files, NULL);
	if (tmp && tmp->directories == type)
		MULTI(start_files, new, tmp);
	while (store->argc && argv && argv[line])
	{
		if ((tmp = create_cells(argv[line], store, 1)))
		{
			store->len_print = compare_len(store->flags, tmp
											, store->len_print);
			tmp->display = store->len_print;
			if (tmp->directories == type && !new) 
				MULTI(start_files, new, tmp);
			else if (tmp->directories == type)
			{
				new->next = tmp;
				new = new->next;
			}
		}
		line++;
	}
	start_files = sort_list(start_files, store);
	return (start_files);
}

t_file 		*build_args_list(char **argv, t_store *store)
{
	FT_INIT(t_file*, start_new, NULL);
	FT_INIT(t_file*, start_files, NULL);
	FT_INIT(t_file*, start_dir, NULL);
	if (!store->argc)
		return (create_cells(".", store, 0));
	start_files = build_args_cells(argv, store, 0);
	start_dir = build_args_cells(argv, store, 1);
	start_new = start_files;
	if (start_dir)
		ft_lstadd_end_ls(&start_new, start_dir);
	return (start_new);
}
/*
t_file 		*build_args_list(char **argv, t_store *store)
{
	FT_INIT(int, line, 1);
	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, tmp, NULL);
	FT_INIT(t_file*, dir_list, NULL);
	FT_INIT(t_file*, start_new, NULL);
	FT_INIT(t_file*, start_list, NULL);
	FT_INIT(t_file*, start_dir, NULL);
	if (!store->argc)
		return (tmp = create_cells(".", store, 0));
	tmp = create_cells(argv[0], store, 1) ;
	if (tmp && tmp->directories)
		MULTI(start_dir, dir_list, tmp);
	else
		MULTI(start_list, new, tmp);
	while (store->argc && argv && argv[line])
	{
		if ((tmp = create_cells(argv[line], store, 1)))
		{
			store->len_print = compare_len(store->flags, tmp, store->len_print);
			tmp->display = store->len_print;
			if (!tmp->directories && !new)
				MULTI(start_list, new, tmp);
			else if (!tmp->directories)
			{
				new->next = tmp;
				new = new->next;
			}
			if (tmp->directories && !dir_list)
				MULTI(start_dir, dir_list, tmp);
			else if (tmp->directories)
			{
				dir_list->next = tmp;
				dir_list = dir_list->next;
			}
		}
		line++;
	}
	start_list = sort_list(start_list, store);
	start_dir = sort_list(start_dir, store);
	start_new = start_list;
	if (start_dir)
		ft_lstadd_end_ls(&start_new, start_dir);
	return (start_new);
}*/

static int 	cat_list(t_file *new, t_store *store, t_file **files, int nb_dir)
{
	if (!new)
	{
		store->add_args = NULL;
		return (0);
	}
	if (!(*files))
		MULTI(store->start_list, *files, sort_list(new, store));
	else
	{
		(*files)->next = sort_list(new, store);
		*files = (*files)->next;
	}
	(*files)->nb_blocks = store->nb_blocks;
	(*files)->display = store->len_print;
	store->add_args = flag_R(*files, nb_dir, store);
	while (*files && (*files)->next)
		*files = (*files)->next;
	return (1);
}

int			build_list(char *file, char *rights, t_store *store, t_file **list)
{
	struct stat infos;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(DIR*, rep, NULL);
	FT_INIT(int, nb_dir, 0);
	if (ft_strcmp(file, "."))
		store->path = file[ft_strlen(file) - 1] != '/' ? ft_strjoin(file, "/") 
		: ft_strdup(file);
	else
		store->path = ft_strdup("./");
	if (!(rep = opendir(file)) || (store->flags && ft_strchr(rights, 'l') 
	&& ft_strchr(store->flags, 'l')))
	{
		if (lstat(file, &infos) == -1)
			return (perror_ls(file));
		new = create_cells(file, store, 1);
		new->display = compare_len(store->flags, new, store->len_print);
	}
	else
		new = read_elements(store, &nb_dir, rep);
	if (rep && closedir(rep) == -1)
		return (perror_ls(file));
	return (cat_list(new, store, list, nb_dir));
}