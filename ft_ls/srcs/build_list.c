#include "../includes/ft_ls.h"

t_file		*create_cells(struct dirent* fd, t_store *store)
{
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(fd->d_name);
	new->path = ft_strdup(store->path);
	new->date = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->directories = NULL;
	return (new);
}

int			build_list(t_file **files, struct dirent* fd, t_store *store)
{
	if (*files)
	{
		(*files)->next = create_cells(fd, store);
		(*files)->prev = (*files);
		*files = (*files)->next;
	}
	else if (!(*files))
		MULTI(store->start_list, (*files), create_cells(fd, store));
	return (1);
}