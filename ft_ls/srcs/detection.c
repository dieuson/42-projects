/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:16:58 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/16 14:20:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			**reject_flags(char ***args, int ligne, int argc)
{
	while ((ligne + 1) < argc)
	{
		(*args)[ligne] = (*args)[ligne + 1];
		ligne++;
	}
	(*args)[ligne] = NULL;
	return (*args);
}

int				verif_flag_a(t_store *store, char *name)
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

int				store_flag(char ***argv, int argc, t_store *store, int line)
{
	FT_INIT(int, colonne, 1);
	if (!ft_strcmp((*argv)[line], "--help"))
		return (print_help());
	while ((*argv)[line][colonne])
	{
		if (!ft_strchr("lartR", (*argv)[line][colonne]))
			return (error_flags((*argv)[line][colonne]));
		colonne++;
	}
	if (!store->flags)
		store->flags = ft_strdup("00000");
	(store->flags)[0] = ft_strchr((*argv)[line], 'l') ? 'l' : (store->flags)[0];
	(store->flags)[1] = ft_strchr((*argv)[line], 'a') ? 'a' : (store->flags)[1];
	(store->flags)[2] = ft_strchr((*argv)[line], 'r') ? 'r' : (store->flags)[2];
	(store->flags)[3] = ft_strchr((*argv)[line], 't') ? 't' : (store->flags)[3];
	(store->flags)[4] = ft_strchr((*argv)[line], 'R') ? 'R' : (store->flags)[4];
	*argv = reject_flags(&(*argv), line, argc);
	return (1);
}

char			**verif_double_flags(char **argv, int *argc)
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

int				detect_flags(char ***argv, int argc, t_store *store)
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
	*argv = verif_double_flags(*argv, &argc);
	store->argc = argc;
	return (1);
}
