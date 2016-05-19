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

t_file				*create_simple_cells(char *name, t_store *store)
{
	struct stat		infos;

	if (stat(name, &infos) == -1)
	{
		perror_ls(name);
		return (NULL);
	}
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strnchr(name, '/', 2) ? ft_strdup(ft_strnchr(name, '/', 2) + 1) : ft_strdup(name);
	new->path = NULL;
	new->absolute_path = ft_strdup(name);
	new->owner = get_owner(infos);
	new->owner_grp = get_owner_grp(infos);
	if (!(new->date = get_date(infos, 1)))
		(store->flags)[0] = '0';
	new->time_estamp = store->flags && !ft_strchr(store->flags, 't') && 
	ft_strchr(store->flags, 'u') ? infos.st_atime : get_time_estamp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->nb_blocks = infos.st_blocks;
	new->rights = get_rights(infos);
	new->next = NULL;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
	new->display = 0;
	return (new);
}

t_file				*create_cells(struct dirent	*fd, t_store *store)
{
	struct stat		infos;

	FT_INIT(char*, path, ft_strjoin(store->path, fd->d_name));
	stat(path, &infos);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(fd->d_name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
//	ft_printf("cell path =%s,\n", new->absolute_path);
	if (store->flags && ft_strchr(store->flags, 'l'))
	{
		new->owner = get_owner(infos);
		new->owner_grp = get_owner_grp(infos);
		if (!(new->date = get_date(infos, 1)))
			(store->flags)[0] = '0';
	}
	new->time_estamp = store->flags && !ft_strchr(store->flags, 't') && 
	ft_strchr(store->flags, 'u') ? infos.st_atime : get_time_estamp(infos);
//	new->time_estamp = infos.st_mtimespec.tv_sec;
//	new->time_lacc = infos.st_atimespec.tv_sec;
//	new->time_chan = infos.st_ctimespec.tv_sec;
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->display = 0;
	new->nb_blocks = infos.st_blocks;
	new->rights = get_rights(infos);
	new->next = NULL;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
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
		return (tmp = create_simple_cells(".", store));
	else
		tmp = create_simple_cells(argv[0], store) ;
	if (tmp && tmp->directories)
		MULTI(start_dir, dir_list, tmp);
	else
		MULTI(start_list, new, tmp);
	while (store->argc && argv && argv[ligne])
	{
		if (!(tmp = create_simple_cells(argv[ligne], store)))
		{
			ligne++;
			continue ;
		}
		if (!tmp->directories && !new)
			MULTI(start_list, new, tmp);
		else if (!tmp->directories)
			MULTI(new, new->next, tmp);
		if (tmp->directories && !dir_list)
			MULTI(start_dir, dir_list, tmp);
		else if (tmp->directories)
			MULTI(dir_list, dir_list->next, tmp);
		ligne++;
	}
	start_list = sort_list(start_list, store);
	start_dir = sort_list(start_dir, store);
	start_new = start_list;
	if (start_dir)
		ft_lstadd_end_ls(&start_new, start_dir);
	return (start_new);
}

int			build_list(char *file, t_store *store, t_file **files)
{
	struct stat infos;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(DIR*, rep, NULL);
	FT_INIT(int, nb_dir, 0);
//	ft_printf("files =%s,\n", file);
	if (ft_strcmp(file, "."))
		store->path = file[ft_strlen(file) - 1] != '/' ? ft_strjoin(file, "/") 
		: ft_strdup(file);
	else
		store->path = ft_strdup("./");
	if (!(rep = opendir(file)))
	{
		if (stat(file, &infos) == -1)
			return (perror_ls(file));
		if (!new)
			new = create_simple_cells(file, store);
		else
		{
			new->next = create_simple_cells(file, store);
			new = new->next;
		}
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