/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:16:58 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/31 15:22:23 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		**reject_flags(char ***args, int ligne, int argc)
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
		if (store->flags && (ft_strchr(store->flags, 'a')
		|| ft_strchr(store->flags, 'f')))
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

static int		store_flag(char ***argv, int argc, t_store *store, int i)
{
	FT_INIT(int, colonne, 1);
	if (!ft_strcmp((*argv)[i], "--help"))
		return (print_help());
	while ((*argv)[i][colonne])
	{
		if (!ft_strchr("lartRugcf", (*argv)[i][colonne]))
			return (error_flags((*argv)[i][colonne]));
		colonne++;
	}
	store->flags = !store->flags ? ft_strdup("000000000") : store->flags;
	(store->flags)[0] = ft_strchr((*argv)[i], 'l') ? 'l' : (store->flags)[0];
	(store->flags)[1] = ft_strchr((*argv)[i], 'a') ? 'a' : (store->flags)[1];
	(store->flags)[2] = ft_strchr((*argv)[i], 'r') ? 'r' : (store->flags)[2];
	(store->flags)[3] = ft_strchr((*argv)[i], 't') ? 't' : (store->flags)[3];
	(store->flags)[4] = ft_strchr((*argv)[i], 'R') ? 'R' : (store->flags)[4];
	(store->flags)[5] = ft_strchr((*argv)[i], 'u') ? 'u' : (store->flags)[5];
	(store->flags)[6] = ft_strchr((*argv)[i], 'g') ? 'g' : (store->flags)[6];
	if (ft_strchr((*argv)[i], 'f'))
	{
		(store->flags)[7] = 'f';
		(store->flags)[3] = '0';
	}
	(store->flags)[8] = ft_strchr((*argv)[i], 'c') ? 'c' : (store->flags)[8];
	*argv = reject_flags(&(*argv), i, argc);
	return (1);
}

static char		**verif_double_flags(char **argv, int *argc)
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
	store->flags = NULL;
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
