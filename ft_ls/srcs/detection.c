#include "../includes/ft_ls.h"

char 		 ***reject_flags(char ***args, int ligne, int argc)
{
	while ((ligne + 1) < argc)
	{
		(*args)[ligne] = (*args)[ligne + 1];
		ligne++;
	}
	return (args);
}

int 			store_flag(char ***argv, int argc, t_store *store, int ligne)
{
	FT_INIT(int, colonne, 1);
	if (!ft_strcmp((*argv)[ligne], "--help"))
		return (print_help());
	while ((*argv)[ligne][colonne])
	{
		if (!ft_strchr("lartR", (*argv)[ligne][colonne]))
			return (error_flags((*argv)[ligne][colonne]));
		colonne++;
	}
	store->flags = ft_strjoin(store->flags, (*argv)[ligne]);
	argv = reject_flags(argv, ligne, argc);
	return (1);
}

int 			detect_flags(char ***argv, int argc, t_store *store)
{
	FT_INIT(int, ligne, 1);
	while (ligne < argc)
	{
		if ((*argv)[ligne][0] == '-')
		{
			if (!store_flag(argv, argc, store, ligne))
				return (0);
			ligne = 0;
			argc--;
		}
		ligne++;
	}
	(*argv)[argc] = NULL;
	store->args = (*argv) + 1;
	store->argc = argc - 1;
	return (1);
}