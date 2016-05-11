#include "../includes/ft_ls.h"

t_file		*create_cells(struct dirent* fd, t_store *store)
{
	struct stat infos;

	FT_INIT(char*, path, ft_strjoin(store->path, fd->d_name));
	stat(path, &infos);
//	ft_printf("path =%s,\n", path);
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(fd->d_name);
	new->path = ft_strdup(store->path);
	new->absolute_path = ft_strdup(path);
//	ft_printf("absolute_path =%s,\n\n", new->absolute_path);
	new->date = get_date(infos);
//	ft_printf("ORIGIN date\n");
//	print_simple_tab(new->date);
//	ft_printf("ORIGIN date\n");
	new->owner =  get_owner(infos);
	new->owner_grp = get_owner_grp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->rights = get_rights(infos);
	new->time_past = get_time_pass(infos);
	new->next = NULL;
	new->prev = NULL;
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
	new->time_past = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->directories = ft_strstr(new->rights, "d") ? 1 : 0;
	return (new);
}

t_file		*build_list(t_file **files, t_store *store, t_file **tab)
{
	FT_INIT(int, line, 1);
	FT_INIT(int, nb_dir, 0);
	FT_INIT(t_file *, verif_dir, NULL);
	if (!tab)
		return (NULL);
	if (!(*files))
		MULTI(store->start_list, (*files), copy_cell(tab[0]));
//		MULTI(store->start_list, (*files), tab[0]);
	verif_dir = *files;
	while (tab && tab[line])
	{
		if (ft_strchr((tab[line])->rights, 'd'))
		{
		//	ft_putstr("DIR\n");
			nb_dir++;
		}
//		(*files)->next = tab[line];
		(*files)->next = copy_cell(tab[line]);
		*files = (*files)->next;
		line++;
	}
	if (nb_dir && store->flags && ft_strstr(store->flags, "R"))
	{
	//	ft_putstr("test segfault\n");
		store->tab = flag_R(verif_dir, nb_dir);
	//	ft_putstr("end test segfault\n");
	}
//	else
//		store->tab = NULL;
	return (*files);
}