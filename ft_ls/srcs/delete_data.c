#include "../includes/ft_ls.h"

void 		free_struct(t_store *store)
{
	ft_strdel(&(store->path));
	ft_strdel(&(store->flags));
//	free_simple_tab(&store->tab);
	free(&store->start_list);
//	ft_memdel((void**)&store->start_list);
}

void 		free_list(t_file *files)
{
	t_file 	*tmp;
	FT_INIT(int, line, 0);

	while ((files))
	{
		tmp = (files)->next;
		ft_strdel(&(files)->path);
		ft_strdel(&(files)->name);
		free_simple_tab(&(files)->date);
		free(files->date);
		while ((files->time_estamp)[line])
		{
			free(&(files->time_estamp)[line]);
			line++;
		}
		line = 0;
		ft_strdel(&(files)->rights);
		ft_strdel(&(files)->absolute_path);
		ft_memdel((void**)&(files));
		files = tmp;
	}
	files = NULL;
}