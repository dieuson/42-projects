#include "../includes/ft_ls.h"

int 		parse_dir(char *file, t_file **files, t_store *store)
{
//	DIR* 	rep;

//	ft_printf("file =%s\n", file);
//	ft_putstr("test20\n");
//	if (!(rep = opendir(file)))
//		return (perror_ls());
//	ft_putstr("test01\n");
	if (ft_strcmp(file, "."))
		store->path = ft_strdup(file);
	else
		store->path = ft_strdup("./");
//	if (closedir(rep) == -1)
//		return (perror_ls());
//	ft_putstr("test02\n");
//	sort_files(file, store, files);
//	ft_putstr("test23\n");
//	return (0);
	sort_files(file, store, files);
	ft_strdel(&store->path);
	return (1);
}

char 		**copy_argv(char **argv)
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
	FT_INIT(char **, argv_2, NULL);
	FT_INIT(char **, to_del, NULL);

//	ft_printf("argv2 =%s,\n", argv_2[ligne]);
	if (!store->argc)
	{	
		parse_dir(".", &files, store);
		if (store->tab)
		{
			to_del = argv_2;
			argv_2 = ft_strjoin_tab(argv_2, store->tab);
			free_simple_tab(&to_del);
			store->tab = NULL;
		}
	}
	else
		argv_2 = copy_argv(argv);
//	ft_printf("tab argv2\n");
//	print_simple_tab(argv_2);
//	ft_printf("tab end argv2\n");
	while (argv_2 && argv_2[ligne])
	{
//		ft_printf("argv2 =%s,\n", argv_2[ligne]);
//		ft_putstr("test00\n");
//		ft_printf("start parser\n");
		parse_dir(argv_2[ligne], &files, store);
//		ft_printf("end parser\n");
//		ft_putstr("test01\n");
		if (store->tab)
		{
//			ft_printf("debut\n");
			to_del = argv_2;
			argv_2 = ft_strjoin_tab(argv_2, store->tab);
			free_simple_tab(&to_del);
//			ft_printf("FIN\n");
			store->tab = NULL;
		}
//		ft_putstr("test02\n");
		ligne++;
	}	
	print_data(store);
	free_simple_tab(&store->tab);
//	free_simple_tab(&argv_2);
	free_list(store->start_list);
	return (NULL);
}