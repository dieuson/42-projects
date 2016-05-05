#include "../includes/ft_ls.h"

char 		 **reject_flags(char ***args, int ligne, int argc)
{
	while ((ligne + 1) < argc)
	{
		(*args)[ligne] = (*args)[ligne + 1];
		ligne++;
	}
//	 (*args)[ligne - 1] = NULL;
	return (*args);
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
	if (store->flags)
		store->flags = ft_strjoin(store->flags, (*argv)[ligne]);
	else
		store->flags = ft_strdup((*argv)[ligne]);
	*argv = reject_flags(&(*argv), ligne, argc);
	return (1);
}

char 			**verif_double(char **argv, int *argc)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 0);
	while (ligne < *argc)
	{
		while (ligne2 < *argc)
		{
			if (!ft_strcmp(argv[ligne], argv[ligne2]))
			{
				argv = reject_flags(&argv, ligne2, *argc);
				(*argc)--;
				ligne = 0;
				ligne2 = ligne + 1;
			}
			else
				ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
	return (argv);
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
	*argv = verif_double(*argv, &argc);
	store->argc = (argc - 1) <= 0 ? 0 : (argc - 1);
//	ft_printf("nb args =%d,\n", store->argc);
//	ft_putstr("argv\n");
//	print_simple_tab(*argv);
//	ft_putstr("end argv\n");
	return (1);
}