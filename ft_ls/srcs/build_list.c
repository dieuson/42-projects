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

t_file			*create_cells(char *name, t_store *store, int type)
{
	struct stat		infos;
	char			*path;

	FT_INIT(char *, flags, store->flags);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	path = !type ? ft_strjoin(store->path, name) : ft_strdup(name);
	lstat(path, &infos);
	new->name = ft_strdup(name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
	new = get_owners(infos, new);
	if (!(new->date = get_date(infos, flags)))
		(flags)[0] = '0';
	new->rights = get_rights(infos);
	new->private = NULL;
	if (flags && ft_strchr(flags, 'l') && ft_strchr(new->rights, 'l'))
		new->private = ft_strrchr(new->name, '/') ?
			ft_strdup(ft_strrchr(new->name, '/') + 1) : ft_strdup(new->name);
	new = get_integers_data(infos, new, flags);
	store->nb_blocks += new->nb_blocks;
	new->next = NULL;
	ft_strdel(&path);
	return (new);
}

static	t_file	*build_args_cells(char **argv, t_store *store, int type)
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

t_file			*build_args_list(char **argv, t_store *store)
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
	store->nb_blocks = 0;
	return (start_new);
}

static	int		cat_lst(t_file *new, t_store *store, t_file **lst, int nb_dir)
{
	if (!new)
	{
		store->add_args = NULL;
		return (0);
	}
	if (!(*lst))
		MULTI(store->start_list, *lst, sort_list(new, store));
	else
	{
		(*lst)->next = sort_list(new, store);
		*lst = (*lst)->next;
	}
	(*lst)->nb_blocks = store->nb_blocks;
	(*lst)->display = store->len_print;
	store->add_args = flag_r(*lst, nb_dir, store);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	return (1);
}

int				build_list(char *file, char *rights, t_store *store,
				t_file **list)
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
		if (lstat(file, &infos) == -1 || get_file_type(infos) == 'd')
			return (perror_ls(file));
		new = create_cells(file, store, 1);
		new->display = compare_len(store->flags, new, store->len_print);
	}
	else
		new = read_elements(store, &nb_dir, rep);
	if (rep && closedir(rep) == -1)
		return (perror_ls(file));
	return (cat_lst(new, store, list, nb_dir));
}
