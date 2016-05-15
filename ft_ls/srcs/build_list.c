#include "../includes/ft_ls.h"

t_file		*create_cells(struct dirent* fd, t_store *store)
{
	struct stat infos;

	FT_INIT(char*, path, ft_strjoin(store->path, fd->d_name));
	stat(path, &infos);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(fd->d_name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
//	if (store->flags && ft_strchr(store->flags, 'l'))
//	{

		new->owner =  get_owner(infos);
		new->owner_grp = get_owner_grp(infos);
		new->date = get_date(infos, 1);
//	}
//	if (store->flags && ft_strchr(store->flags, 't'))
		new->time_estamp = get_time_estamp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->display = 0;
	new->rights = get_rights(infos);
	new->next = NULL;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
	ft_strdel(&path);
	return (new);
}

t_file 		*copy_cell(t_file *cell)
{
	if (!cell)
		return (NULL);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(cell->name);
	new->path = ft_strdup(cell->path);
	new->absolute_path = ft_strdup(cell->absolute_path);
	new->date = new_simple_tab(&(cell->date));
	new->owner =  ft_strdup(cell->owner);
	new->owner_grp = ft_strdup(cell->owner_grp);
	new->size = cell->size;
	new->link = cell->link;
	new->rights = ft_strdup(cell->rights);
	new->time_estamp = NULL;
	new->next = NULL;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
	return (new);
}
