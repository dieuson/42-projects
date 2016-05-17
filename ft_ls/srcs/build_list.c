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

	stat(name, &infos);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(name);
	if (store->flags && ft_strchr(store->flags, 'l'))
	{
		new->owner = get_owner(infos);
		new->owner_grp = get_owner_grp(infos);
		if (!(new->date = get_date(infos, 1)))
			(store->flags)[0] = '0';
	}
	new->time_estamp = store->flags && !ft_strchr(store->flags, 't') && 
	ft_strchr(store->flags, 'u') ? infos.st_atime : get_time_estamp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->display = 0;
	new->nb_blocks = infos.st_blocks;
	new->rights = get_rights(infos);
	new->next = NULL;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
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
