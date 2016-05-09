#include "../includes/ft_ls.h"

int						ft_strcmp_abs(const char *s1, const char *s2)
{
	int					i;
	int 				e;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	e = 0;
	while (str1[i] && str2[e])
	{
		if (str1[i] == '.')
			i++;
		if (str2[e] == '.')
			e++;
		if (ft_tolower(str1[i]) != ft_tolower(str2[e]))
			return (ft_tolower(str1[i]) - ft_tolower(str2[e]));
		i++;
		e++;
	}
	return (ft_strlen(s1) - ft_strlen(s2));
}

int 		compare_date(t_file *cell1, t_file *cell2)
{
	FT_INIT(int*, s1, cell1->time_past);
	FT_INIT(int*, s2, cell2->time_past);
	FT_INIT(int, verif, 0);
	verif += s1[0] - s2[0];
	verif += (!verif && s1[0] == s2[0]) ?(s1[1] - s2[1]) : verif;
	verif += (!verif && s1[1] == s2[1]) ?(s1[2] - s2[2]) : verif;
	verif += (!verif && s1[2] == s2[2]) ?(s1[3] - s2[3]) : verif;
	verif += (!verif && s1[3] == s2[3]) ?(s1[4] - s2[4]) : verif;
	verif += (!verif && s1[4] == s2[4]) ?(s1[5] - s2[5]) : verif;
	verif += (!verif && s1[5] == s2[5]) ? ft_strlen(cell1->name) - ft_strlen(cell2->name) : 0;
	return (verif);
}


int 		compare(t_file *s1, t_file *s2, t_store *store)
{
	if (store->flags)
	{
		if (ft_strchr(store->flags, 't'))
		{
			if(!ft_strchr(store->flags, 'r') && compare_date(s1, s2) < 0)
				return (1);
			if (ft_strchr(store->flags, 'r') && compare_date(s1, s2) > 0)
				return (1);
		}
		else if (ft_strchr(store->flags, 'r'))
		{
			if (ft_strcmp_abs(s1->name, s2->name) < 0)
				return (1);
		}
		else if (ft_strcmp_abs(s1->name, s2->name) > 0)
				return (1);
	}
	else
	{
		if (ft_strcmp_abs(s1->name, s2->name) > 0)
			return (1);
	}
	return (0);
}

t_file 		**sort_tab_list(t_file **tab, t_store *store)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	FT_INIT(t_file*, tmp, NULL);
	while (tab[ligne])
	{
		while (tab[ligne2])
		{
			if (compare(tab[ligne], tab[ligne2], store))
			{
				tmp = tab[ligne2];
				tab[ligne2] = tab[ligne];
				tab[ligne] = tmp;
				ligne = 0;
				ligne2 = 1;
			}
			else
				ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
	return (tab);
}

int 				nb_files(char *file, t_store *store)
{
	DIR 			*rep;
	struct dirent 	*fd;

	FT_INIT(int, nb_args, 1);
	if (!(rep = opendir(file)))
		return (perror_ls());
	while((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		nb_args++;
	}
	if (closedir(rep) == -1)
		return (perror_ls());
	return (nb_args);
}

int			sort_files(char *file, t_store *store, t_file **files)
{
	t_file **tab;
	DIR* 	rep;
	struct dirent *fd;

	FT_INIT(int, ligne, 0);
	tab = (t_file**)malloc(sizeof(t_file*) *  nb_files(file, store));
	if (!(rep = opendir(file)))
		return (perror_ls());
	while((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		tab[ligne] = create_cells(fd, store);
		ligne++;
	}
	if (closedir(rep) == -1)
		return (perror_ls());
	tab[ligne] = NULL;
	tab = sort_tab_list(tab, store);
	build_list(&(*files), store, tab);
	free_tab_cell(&tab);
	return (1);
}