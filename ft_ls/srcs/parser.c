#include "../includes/ft_ls.h"

int 		parse_dir(char *file, t_file **files, t_store *store)
{
	DIR* 	rep;

	ft_printf("file =%s\n", file);
	if (!(rep = opendir(file)))
		return (perror_ls());
	if (ft_strcmp(file, "."))
		store->path = ft_strdup(file);
	else
		store->path = ft_strdup("./");
	sort_files(file, store, files);
	if (closedir(rep) == -1)
		return (perror_ls());
	ft_strdel(&store->path);
	return (0);
}



char 		**parse_args(char **argv, t_file *files, t_store *store)
{
	FT_INIT(int, ligne, 0);
	if (!store->argc)
	{	
		parse_dir(".", &files, store);
		if (store->tab)
		{
			argv = ft_strjoin_tab(argv, store->tab);
		//	free_simple_tab(&store->tab);
			store->tab = NULL;
		}
	}	
	while (argv && argv[ligne])
	{
		parse_dir(argv[ligne], &files, store);
		if (store->tab)
		{
			argv = ft_strjoin_tab(argv, store->tab);
			store->tab = NULL;
		}
		ligne++;
	}	
//	print_data(store);
	free_simple_tab(&store->tab);
	free_list(&files);
//		ft_strdel(&store->path);
	return (NULL);
}