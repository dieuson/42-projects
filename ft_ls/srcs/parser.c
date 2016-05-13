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

int 		*create_int_tab(int len)
{
	int 	*fraiche;

	FT_INIT(int, line, 0);
 	fraiche = (int*)malloc(sizeof(int) * len);
 	while (line < len)
 	{
 		fraiche[line] = 0;
 		line++;
 	}
 	return (fraiche);
}

int 		len_str(char *str)
{
	FT_INIT(int, len, 0);
	while (str && str[len])
		len++;
	return (len);
}

int 		len_nb(int nb)
{
	FT_INIT(int, len, 0);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int 		*compare_len(t_file *files, int *tab)
{
	tab[0] = len_str(files->rights) > tab[0] ? len_str(files->rights) : tab[0];
	tab[1] = len_nb(files->link) > tab[1] ? len_nb(files->link) : tab[1];
	tab[2] = len_str(files->owner) > tab[2] ? len_str(files->owner) : tab[2];
	tab[3] = len_str(files->owner_grp) > tab[3] ? len_str(files->owner_grp) : tab[3];
	tab[4] = len_nb(files->size) > tab[4] ? len_nb(files->size) : tab[4];
	tab[5] = len_str(files->date[0]) > tab[5] ? len_str(files->date[0]) : tab[5];
	tab[6] = len_str(files->date[1]) > tab[6] ? len_str(files->date[1]) : tab[6];
	tab[7] = len_str(files->date[2]) > tab[7] ? len_str(files->date[2]) : tab[7];
	tab[8] = len_str(files->name) > tab[8] ? len_str(files->name) : tab[8];
	return (tab);
}

t_file		*read_elements(t_store *store, int *nb_dir, DIR *rep)
{
	struct dirent *fd;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, start_new, NULL);
	FT_INIT(int*, len_print, NULL);

	len_print = create_int_tab(9);
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
		len_print = compare_len(new, len_print);
		new->display = len_print;
		if (store->flags && ft_strchr(store->flags, 'R') 
		&& ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
			(*nb_dir) += ft_strchr(new->rights, 'd') ? 1 : 0;
	}
	start_new->display = len_print;
	return (start_new);
}

int			sort_files(char *file, t_store *store, t_file **files)
{
	FT_INIT(t_file*, new, NULL);
	FT_INIT(DIR*, rep, NULL);
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
	{
		(*files)->next = sort_list(new, store);
		*files = (*files)->next;
	}
	store->tab = flag_R(*files, nb_dir, store);
	while (*files && (*files)->next)
		*files = (*files)->next;
	return (1);
}

t_args 		*create_cells_args(char *name)
{
	FT_INIT(t_args*, new, NULL);
	new = (t_args*)malloc(sizeof(t_args));
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

t_args 		*build_args_list(char **argv, t_store *store)
{
	FT_INIT(int, ligne, 1);
	FT_INIT(t_args*, new, NULL);
	FT_INIT(t_args*, start_new, NULL);
	if (!store->argc)
		return (new = create_cells_args("."));
	else
		new = create_cells_args(argv[0]);
	start_new = new;
	while (store->argc && argv && argv[ligne])
	{
		new->next = create_cells_args(argv[ligne]);
		ligne++;
		new = new->next;
	}
//	if (store->tab)
//		free_simple_tab(&(store->tab));
	return (start_new);
}

void		ft_lstadd_end_ls(t_args **alst, t_args *new)
{
	t_args 	*node;

	if (*alst)
	{
		node = *alst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

char 		**parse_args(char **argv, t_file *files, t_store *store)
{
	
	FT_INIT(t_args*, args, NULL);
	FT_INIT(t_args*, add, NULL);
	FT_INIT(t_args*, tmp, NULL);
	args = build_args_list(argv, store);
	while (args)
	{
		sort_files(args->name, store, &files);
		ft_strdel(&store->path);
		if (store->tab)
		{
			add = build_args_list(store->tab, store);
			store->argc = 1;
			tmp = args->next;
			args->next = add;
			ft_lstadd_end_ls(&args, tmp);
		}
	//	ft_strdel(&to_del->name);
	//	ft_memdel((void**)&(to_del));
		args = args->next;
	}	
	print_data(store);
	
//	free_simple_tab(&argv2);
//	free_list(store->start_list);
	return (NULL);
}