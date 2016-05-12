#include "../includes/ft_ls.h"

int 		parse_dir(char *file, t_file **files, t_store *store)
{
	if (ft_strcmp(file, "."))
	{
		if (file[ft_strlen(file) - 1] != '/')
			store->path = ft_strjoin(file, "/");
		else
			store->path = ft_strdup(file);
//		store->path = ft_strjoin(file, "/");
	}
//		store->path = ft_strdup(file);
	else
		store->path = ft_strdup("./");
	sort_files(file, store, files);
	ft_strdel(&store->path);
	return (1);
}

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
		parse_dir(argv2[ligne], &files, store);
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