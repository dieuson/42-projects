#include "../includes/ft_ls.h"

char 		**verif_dir_double(char **ref)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, line2, 1);
	FT_INIT(char*, to_del, NULL);
	if (!ref)
		return (NULL);	
	while (ref[line])
	{
		while (ref[line2])
		{
			if (ref[line] && ref[line2] && !ft_strcmp(ref[line], ref[line2]))
			{
				to_del = ref[line2];
				while (ref[line2] && ref[line2 + 1])
				{
					ref[line2] = ref[line2 + 1];
					line2++;
				}
				ft_strdel(&to_del);
				ref[line2] = NULL;
			}
			else
				line2++;
		}
		line++;
		line2 = line + 1;
	}
	return (ref);
}

int 		ft_strcmp_tab(char **tab, char *str)
{
	FT_INIT(int, line, 0);
	while (tab[line])
	{
		if (!ft_strcmp(tab[line], str))
			return (1);
		line++;
	}
	return (0);
}

int 		ft_len_tab(void **tab)
{
	FT_INIT(int, len, 0);
	while (tab && tab[len])
		len++;
	return (len);
}

char 		**ft_strjoin_tab(char **t1, char **t2)
{
	FT_INIT(int, line_cop, 0);
	FT_INIT(int, line, 0);
	FT_INIT(char**, fraiche, NULL);
	if (!t2)
		return (NULL);
	if (!t1)

		return(ft_strdup_tab(t2));
	fraiche = (char**)malloc(sizeof(char*) * 
	(ft_len_tab((void**)t1) + ft_len_tab((void**)t2)));
	fraiche[0] = NULL;
	while (t1[line_cop])
	{
//		if (!ft_strcmp(t1[line_cop], ".") || !ft_strcmp(t1[line_cop], ".."))
//			continue ;
		if (!fraiche[0] || !ft_strcmp_tab(fraiche, t1[line_cop]))
		{
			fraiche[line] = ft_strdup(t1[line_cop]);
			fraiche[line + 1] = NULL;
			line++;
		}
		line_cop++;
	}
	line_cop = 0;
//	ft_printf("FIRST tab argv2\n");
//	print_simple_tab(fraiche);
//	ft_printf("FIRST tab end argv2\n\n");
	while (t2[line_cop])
	{
		if (!fraiche[0] || !ft_strcmp_tab(fraiche, t2[line_cop]))
		{
			fraiche[line] = ft_strdup(t2[line_cop]);
			fraiche[line + 1] = NULL;
			line++;
		}
		line_cop++;
	}
//	ft_printf("SECOND tab argv2\n");
//	print_simple_tab(fraiche);
//	ft_printf("SECOND tab end argv2\n\n");
	return (fraiche);
}



char 		**flag_R(t_file *files, int nb_dir, t_store *store)
{
	FT_INIT(char **, tab, NULL);
	if (!nb_dir || !store->flags || !ft_strchr(store->flags, 'R'))
		return (NULL);
	if (!nb_dir)
		return (NULL);
//	ft_printf("test0\n");
	tab = (char **)malloc(sizeof(char *) * (nb_dir + 1));
//	ft_printf("test1\n");
	nb_dir = 0;
	while (files)
	{
//		if (files && !ft_strstr(files->absolute_path, "/.") && ft_strchr(files->rights, 'd'))
		if (files && ft_strchr(files->rights, 'd') && ft_strcmp(files->name, ".") && ft_strcmp(files->name, ".."))
		{
//			ft_putstr("test3\n");
			tab[nb_dir] = ft_strdup(files->absolute_path);
			if (tab[nb_dir][ft_strlen(tab[nb_dir]) - 1] != '/')
				tab[nb_dir] = ft_strjoin(tab[nb_dir], "/");
//			ft_putstr("test5\n");
			tab[nb_dir + 1] = NULL;
			nb_dir++;
		}
//		ft_printf("file->name =%s\n", files->name);
		files = files->next;
	}
	return (tab);
}
