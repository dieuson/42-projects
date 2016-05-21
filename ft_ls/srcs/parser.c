#include "../includes/ft_ls.h"

t_file		*read_elements(t_store *store, int *nb_dir, DIR *rep)
{
	struct dirent *fd;

	FT_INIT(t_file*, new, NULL);
	FT_INIT(t_file*, start_new, NULL);
//	FT_INIT(int*, len_print, NULL);
	while ((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		if (!new)
			MULTI(start_new, new, create_cells(fd->d_name, store, 0));
		else
		{
			new->next = create_cells(fd->d_name, store, 0);
			new = new->next;
		}
		store->nb_blocks += new->nb_blocks;
		store->len_print = compare_len(store->flags, new, store->len_print);
		if (store->flags && ft_strchr(store->flags, 'R') 
		&& ft_strcmp(new->name, ".") && ft_strcmp(new->name, ".."))
			(*nb_dir) += ft_strchr(new->rights, 'd') ? 1 : 0;
	}
	return (start_new);
}

int		parse_args(char **argv, t_file *files, t_store *store)
{
	FT_INIT(t_file*, args, NULL);
	FT_INIT(t_file*, add, NULL);
	FT_INIT(t_file*, tmp, NULL);
	FT_INIT(int, verif, 0);
	FT_INIT(int, loop, 0);
	store->len_print = create_int_tab(9);
	args = build_args_list(argv, store);
	FT_INIT(t_file*, start_args, args);
//	print_list(args);
//	return (NULL);
	while (args)
	{
		store->add_args = NULL;
		store->nb_blocks = 0;
		while (loop < 9)
		{
			(store->len_print)[loop] = 0;
			loop++;
		}
		loop = 0;
//		ft_printf("TEST1\n");
		verif = build_list(args->name, args->rights, store, &files);
		if (verif && store->add_args)
		{
			add = store->add_args;
			store->argc = 2;
			tmp = args->next;
			args->next = add;
			ft_lstadd_end_ls(&args, tmp);
		}
		if (args->next)
			store->len_print = create_int_tab(9);
		args = args->next;
	}
	if (verif)
	{
		print_data(store);
		free_list(start_args);

	}
//	ft_putendl("END PRINT");
	return (1);
}