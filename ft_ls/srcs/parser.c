#include "../includes/ft_ls.h"

void 		store_tab(t_store *store, int nb_args, char *name)
{
	char 	**tab_tmp;
	if (nb_args + 1 < store->len_tab)
	{
		store->tab[nb_args] = ft_strdup(name);
		store->tab[nb_args + 1] = NULL;
	}
	else
	{
		tab_tmp = (char**)malloc(sizeof(char*)*store->len_tab * 2);
		store->len_tab *= 2;
		tab_tmp = copy_simple_tab(store->tab, tab_tmp);
		free_simple_tab(&store->tab);
		store->tab = tab_tmp;
		store->tab[nb_args] = ft_strdup(name);
		store->tab[nb_args + 1] = NULL;
	}
}

int 		verif_flag_a(t_store *store, char *name)
{
	if (name[0] == '.')
	{
		if (store->flags && ft_strstr(store->flags, "a"))
			return (1);	
		else
			return (0);
	}
	else
		return (1);
}

int 		parse_dir(struct dirent* fd, char *file, t_file **files, t_store *store)
{
	DIR* 	rep;

	FT_INIT(int, nb_args, 0);
	store->tab = (char**)malloc(sizeof(char*)*store->len_tab);
	if (!(rep = opendir(file)))
		return (perror_ls());
	if (ft_strcmp(file, "."))
		store->path = ft_strdup(file);
	else
		store->path = ft_strdup("./");
	while((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		store_tab(store, nb_args, fd->d_name);
		nb_args++;
	}
	store->tab[nb_args] = NULL;
	distrib_sort_data(&store->tab, store);
	build_list(&(*files), fd, store);
	free_simple_tab(&store->tab);
	if (closedir(rep) == -1)
		return (perror_ls());
	return (0);
}

int 		parse_args(char **argv, t_file *files, t_store *store)
{
	struct dirent* fichierLu;

	fichierLu = NULL;
	FT_INIT(int, ligne, 0);
	while (store->argc && ligne <= store->argc)
	{
		parse_dir(fichierLu, argv[ligne], &files, store);
		ft_strdel(&store->path);
		ligne++;
	}
	if (!store->argc)
		parse_dir(fichierLu, ".", &files, store);
//	print_list(store);
	return (1);
}