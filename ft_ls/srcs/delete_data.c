#include "../includes/ft_ls.h"

void 		free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
	free_simple_tab(&store->tab);
	free(&store->start_list);
//	ft_memdel((void**)&store->start_list);
}

void 		free_tab_cell(t_file **tab)
{
	FT_INIT(int, line, 0);
	while (tab[line])
	{
		ft_strdel(&(tab[line])->path);
		ft_strdel(&(tab[line])->name);
		free_simple_tab(&(tab[line])->date);
		ft_strdel(&(tab[line])->rights);
		ft_strdel(&(tab[line])->absolute_path);
		free(tab[line]);
		tab[line] = NULL;
		line++;
	}
	ft_memdel((void**)&tab);
}

void 		free_list(t_file *files)
{
	t_file 	*tmp;

	while ((files))
	{
		tmp = (files)->next;
		ft_strdel(&(files)->path);
		ft_strdel(&(files)->name);
		free_simple_tab(&(files)->date);
		ft_strdel(&(files)->rights);
		ft_strdel(&(files)->absolute_path);
//		free((files)->directories);
		ft_strdel(&(files)->owner);
		ft_strdel(&(files)->owner_grp);
		ft_memdel((void**)&(files));
		files = tmp;
	}
	files = NULL;
}