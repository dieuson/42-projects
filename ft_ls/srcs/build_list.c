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

	path = !type ? ft_strjoin(store->path, name) : ft_strdup(name);
	lstat(path, &infos);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
	new->owner = get_owner(infos);
	new->owner_grp = get_owner_grp(infos);
	if (!(new->date = get_date(infos, 1)))
		(store->flags)[0] = '0';
	new->rights = get_rights(infos);
	new->private = NULL;
	if (store->flags && ft_strchr(store->flags, 'l') && ft_strchr(new->rights, 'l'))
		new->private = ft_strrchr(new->name, '/') ? ft_strdup(ft_strrchr(new->name, '/') + 1) : ft_strdup(new->name);
	new->time_estamp = store->flags && !ft_strchr(store->flags, 't') && 
	ft_strchr(store->flags, 'u') ? infos.st_atime : infos.st_mtime;
//	time_est = infos.st_mtimespec.tv_sec; ;
//	new->time_estamp = infos.st_mtimespec.tv_sec;
//	new->time_lacc = infos.st_atimespec.tv_sec;
//	new->time_chan = infos.st_ctimespec.tv_sec;
	new->size = infos.st_size;	
	new->link = infos.st_nlink;
	new->display = 0;
	new->nb_blocks = infos.st_blocks;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
	new->next = NULL;
	ft_strdel(&path);
	return (new);
}

t_file 		*build_args_list(char **argv, t_store *store)
{
	FT_INIT(int, ligne, 1);
	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, tmp, NULL);
	FT_INIT(t_file*, dir_list, NULL);
	FT_INIT(t_file*, start_new, NULL);
	FT_INIT(t_file*, start_list, NULL);
	FT_INIT(t_file*, start_dir, NULL);
	if (!store->argc)
		return (tmp = create_cells(".", store, 0));
	else
		tmp = create_cells(argv[0], store, 1) ;
	if (tmp && tmp->directories)
		MULTI(start_dir, dir_list, tmp);
	else
		MULTI(start_list, new, tmp);
	while (store->argc && argv && argv[ligne])
	{
		if (!(tmp = create_cells(argv[ligne], store, 1)))
		{
			ligne++;
			continue ;
		}
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
		ligne++;
	}
	start_list = sort_list(start_list, store);
	start_dir = sort_list(start_dir, store);
	start_new = start_list;
	if (start_dir)
		ft_lstadd_end_ls(&start_new, start_dir);
	return (start_new);
}

int			build_list(char *file, char *rights, t_store *store, t_file **files)
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
//	ft_printf("store->path =%s,\n", store->path);
	if (!(rep = opendir(file)) || (store->flags && ft_strchr(rights, 'l') && ft_strchr(store->flags, 'l')))
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