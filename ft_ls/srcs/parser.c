#include "../includes/ft_ls.h"

char 		**ft_strdup_tab(char **argv)
{
	FT_INIT(int, len, 0);
	FT_INIT(char**, fraiche, NULL);
	while (argv[len])
		len++;
	fraiche = (char**)malloc(sizeof(char*) * len);
	len = 0;
	while (argv[len])
	{
		fraiche[len] = ft_strdup(argv[len]);
		len++;
	}
	fraiche[len] = NULL;
	return (fraiche);
}

t_file		*read_elements(t_store *store, int *nb_dir, DIR *rep)
{
	struct dirent *fd;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, start_new, NULL);
	while ((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		if (!new)
			MULTI(start_new, new, create_cells(fd, store));
		else
		{
			new->next = create_cells(fd, store);
			new = new->next;
		}
		(*nb_dir) += ft_strchr(new->rights, 'd') ? 1 : 0;
	}
	return (start_new);
}

int			sort_files(char *file, t_store *store, t_file **files)
{
	DIR* 	rep;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(int, nb_dir, 0);
	if (ft_strcmp(file, "."))
		store->path = file[ft_strlen(file) - 1] != '/' ? ft_strjoin(file, "/") 
		: ft_strdup(file);
	else
		store->path = ft_strdup("./");
	if (!(rep = opendir(file)))
		return (perror_ls());
	new = read_elements(store, &nb_dir, rep);
	if (closedir(rep) == -1)
		return (perror_ls());
	if (!(*files))
		MULTI(store->start_list, *files, sort_list(new, store));
	else
		(*files)->next = sort_list(new, store);
	store->tab = flag_R(*files, nb_dir, store);
	while ((*files)->next)
		*files = (*files)->next;
	ft_strdel(&store->path);
	return (1);
}

char 		**parse_args(char **argv, t_file *files, t_store *store)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(char **, argv2, NULL);
//	FT_INIT(char **, to_del, NULL);
	if (!store->argc)
	{	
		argv2 = (char**)malloc(sizeof(char*) * 2);
		argv2[0] = ft_strdup(".");
		argv2[1] = NULL;
	}
	else
		argv2 = ft_strdup_tab(argv);
	while (argv2 && argv2[ligne])
	{
		ft_printf("argv =%s,\n", argv2[ligne]);
		sort_files(argv2[ligne], store, &files);
		if (store->tab)
		{
//			to_del = argv2;
//			if (!ft_strcmp(argv2[ligne], "."))
//				ligne--;
			argv2 = ft_strjoin_tab(argv2, store->tab);
//			free_simple_tab(&(store->tab));
//			free_simple_tab(&to_del);
			store->tab = NULL;

		}
		ligne++;
	}	
	print_data(store);
//	free_simple_tab(&store->tab);
//	free_simple_tab(&argv2);
//	free_list(store->start_list);
	return (NULL);
}