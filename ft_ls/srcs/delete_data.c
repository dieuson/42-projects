#include "../includes/ft_ls.h"

void 		free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
	free_simple_tab(&store->tab);
	free(&store->start_list);
//	ft_memdel((void**)&store->start_list);
}

void 		free_tab_cell(t_file ***tab)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, tab_line, 0);
	while ((*tab)[line])
	{
		ft_putstr("FREE1\n");
		ft_strdel(&((*tab)[line])->path);
		ft_putstr("FREE2\n");
		ft_strdel(&((*tab)[line])->name);
		ft_putstr("FREE3\n");
		free_simple_tab(&((*tab)[line])->date);
		ft_putstr("FREE4\n");
		ft_strdel(&((*tab)[line])->rights);
//		ft_memdel((void**)&((*tab)[line]));
		ft_putstr("FREE5\n");
		ft_putstr("FREE6\n");
		ft_strdel(&((*tab)[line])->absolute_path);
		ft_putstr("FREE7\n");
		while (((*tab)[line])->time_past[tab_line])
		{
//				free(&((*tab)[line])->time_past[tab_line]);
			tab_line++;
		}
	//	if (((*tab)[line])->time_past)
	//		free(&((*tab)[line])->time_past);
		tab_line = 0;
		free((*tab)[line]);
		((*tab)[line]) = NULL;
		line++;
	}
	ft_putstr("FREE8\n");
	ft_memdel((void**)&(*tab));
//	free(*tab);
	ft_putstr("FREE9\n");

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