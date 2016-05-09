#include "../includes/ft_ls.h"

void 		free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
	free_simple_tab(&store->tab);
	ft_memdel((void**)&store->start_list);
}

void 		free_tab_cell(t_file ***tab)
{
	FT_INIT(int, line, 0);
	while ((*tab)[line])
	{
		ft_strdel(&((*tab)[line])->path);
		ft_strdel(&((*tab)[line])->name);
		free_simple_tab(&((*tab)[line])->date);
		ft_strdel(&((*tab)[line])->rights);
		ft_memdel((void**)&((*tab)[line]));
		((*tab)[line]) = NULL;
		line++;
	}
	free(*tab);

}

void 		free_list(t_file **files)
{
	t_file 	*tmp;

	while ((*files))
	{
		tmp = (*files)->next;
		ft_strdel(&(*files)->path);
		ft_strdel(&(*files)->name);
		free_simple_tab(&(*files)->date);
		ft_strdel(&(*files)->rights);
//		free((*files)->directories);
		ft_memdel((void**)&(*files));
		*files = tmp;
	}
}