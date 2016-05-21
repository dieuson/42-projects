#include "../includes/ft_ls.h"

void		ft_lstadd_end_ls(t_file **alst, t_file *new)
{
	t_file 	*node;

	if (*alst)
	{
		node = *alst;
		while (node->next)
		{
			node = node->next;
		}
		node->next = new;
	}
	else
		*alst = new;
}

t_file 		*flag_R(t_file *files, int nb_dir, t_store *store)
{
	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, start_new, NULL);
	FT_INIT(char*, tmp, NULL);
	if (!nb_dir || !store->flags || !ft_strchr(store->flags, 'R'))
		return (NULL);
	while (files)
	{
		if (files && ft_strchr(files->rights, 'd') && ft_strcmp(files->name, ".") 
		&& ft_strcmp(files->name, ".."))
		{
			tmp = files->absolute_path;
			if (tmp[ft_strlen(tmp) - 1] != '/')
				tmp = ft_strjoin(tmp, "/");
			if (!new)
				MULTI(start_new, new, create_cells(tmp, store, 0));
			else
			{
				new->next = create_cells(tmp, store, 0);
				new = new->next;
			}
		}
		files = files->next;
	}
	return (start_new);
}