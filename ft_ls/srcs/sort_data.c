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
	//		if (ft_strcmp_abs(s1->name, s2->name) < 0)
	//			return (1);
			if (ft_strcmp(s1->name, s2->name) < 0)
				return (1);
		}
		else if (ft_strcmp(s1->name, s2->name) > 0)
				return (1);
//		else if (ft_strcmp_abs(s1->name, s2->name) > 0)
//				return (1);
	}
	else
	{
		if (ft_strcmp(s1->name, s2->name) > 0)
			return (1);
//		if (ft_strcmp_abs(s1->name, s2->name) > 0)
//			return (1);
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

	FT_INIT(int, nb_args, 0);
	//ft_putstr("nb_files1\n");
//	ft_printf("file =%s,\n", file);
	if (!(rep = opendir(file)))
		return (0);
//		return (perror_ls() * 0);
	//ft_putstr("nb_files2\n");
	while((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		nb_args++;
	}
	//ft_putstr("nb_files3\n");
	if (closedir(rep) == -1)
		return (perror_ls() * 0);
	return (nb_args);
}

void 		print_list_ls(t_file *start)
{
	t_file *tmp;

	tmp = start;
	while (tmp)
	{
		ft_printf("tmp->name =%s,\n", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_file 		*sort_list(t_file *liste, t_store *store, int len)
{
	t_file 	*copy_list;
	t_file 	*tmp;
	t_file 	*final;
	t_file 	*start_list;
	t_file 	*list;

	FT_INIT(int, ref, len);
	FT_INIT(int, final_nb, len);
	list = liste;
	start_list = list;
	copy_list = start_list->next;
	tmp = start_list;
	final = NULL;
	ft_printf("LIST\n");
	print_list_ls(list);
	ft_printf("END LIST\n");
	while (copy_list && final_nb >= 0)
	{
		ft_putstr("test\n");
		if (final != tmp && final != copy_list && compare(tmp, copy_list, store))
		{
			ft_putstr("if\n");
			ft_printf("name =%s,\n", tmp->name);
//			tmp = copy_list;
			len = ref;
			copy_list = copy_list->next;
		}
		else
		{
			len--;
			copy_list = list;
			tmp = copy_list;
			ft_printf("else name =%s,\n", tmp->name);
		}
		if (len <= 0)
		{
			if (!final)
			{
				ft_putstr("first cell\n");
				final = tmp;
				start_list = final;
			}
			else
			{
				ft_putstr("ADD cell\n");
				final->next = tmp;
				final = final->next;
				ft_printf("FINAL\n");
				print_list_ls(start_list);
				ft_printf("END FINAL\n\n");
			}
			ft_printf("final_nb =%d\n", final_nb);
			len = ref;
			copy_list = list;
			tmp = copy_list;
			final_nb--;
		}
		ft_printf("final_nb =%d\n", final_nb);
		ft_printf("len =%d,\n", len);
	}
	return (start_list);
}

int			sort_files(char *file, t_store *store, t_file **files)
{
	t_file *list;
	t_file *start_list;
	DIR* 	rep;
	struct dirent *fd;

	FT_INIT(int, len, 0);
	if (!(rep = opendir(file)))
		return (perror_ls());
	list = NULL;
	while ((fd = readdir(rep)))
	{
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		if (!len)
		{
			list = create_cells(fd, store);
			start_list = list;
		}
		else
		{
			list->next = create_cells(fd, store);
			list = list->next;
		}
		len++;
	}
	ft_printf("start->name =%s\n", start_list->name);
	list = sort_list(start_list, store, len);
//	tab = (t_file**)malloc(sizeof(t_file*) *  (len + 1));
	//ft_putstr("test22\n");
	if (closedir(rep) == -1)
		return (perror_ls());
//	tab[ligne] = NULL;
//	tab = sort_tab_list(tab, store);
	//ft_putstr("test23\n");
//	build_list(&(*files), store, tab);
	//ft_putstr("test20\n");
//	free_tab_cell(tab);
	//ft_putstr("test21\n");
	if (files)
		return (1);
	//ft_strdel(&file);
	return (1);
}

/*
int			sort_files(char *file, t_store *store, t_file **files)
{
	t_file **tab;
	DIR* 	rep;
	struct dirent *fd;

	FT_INIT(int, ligne, 0);
	//ft_putstr("test19\n");
	FT_INIT(int, len, 0);
	//ft_putstr("test20\n");
	if (!(len =  nb_files(file, store)))
		return (0);
	tab = (t_file**)malloc(sizeof(t_file*) *  (len + 1));
	if (!(rep = opendir(file)))
		return (perror_ls());
	//ft_putstr("test21\n");
	while((fd = readdir(rep)))
	{
//		//ft_printf("debut\n");
		if (!verif_flag_a(store, fd->d_name))
			continue ;
		tab[ligne] = create_cells(fd, store);
		ligne++;
//		ft_printf("FIN\n\n");
	}
	//ft_putstr("test22\n");
	if (closedir(rep) == -1)
		return (perror_ls());
	tab[ligne] = NULL;
	tab = sort_tab_list(tab, store);
	//ft_putstr("test23\n");
	build_list(&(*files), store, tab);
	//ft_putstr("test20\n");
	free_tab_cell(tab);
	//ft_putstr("test21\n");
	if (files)
		return (1);
	//ft_strdel(&file);
	return (1);
}*/