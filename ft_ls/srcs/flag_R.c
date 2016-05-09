#include "../includes/ft_ls.h"

char 		**verif_dir_double(char **ref)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, line2, 1);
	if (!ref)
		return (NULL);	
	while (ref[line])
	{
		while (ref[line2])
		{
			if (ref[line] && ref[line2] && !ft_strcmp(ref[line], ref[line2]))
			{
				while (ref[line2] && ref[line2 + 1])
				{
					ref[line2] = ref[line2 + 1];
					line2++;
				}
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

char 		**ft_strjoin_tab(char **t1, char **t2)
{
	FT_INIT(int, len_t1, 0);
	FT_INIT(int, len_t2, 0);
	FT_INIT(int, line, 0);
	FT_INIT(char**, fraiche, NULL);
	if (!t1 || !t2)
		return (NULL);
	while (t1[len_t1])
		len_t1++;
	while (t2[len_t2])
		len_t2++;
	fraiche = (char**)malloc(sizeof(char*) * (len_t1 + len_t2));
	fraiche = copy_simple_tab(t1, fraiche);
	while (line < len_t2)
	{
		fraiche[len_t1] = ft_strdup(t2[line]);
		len_t1++;
		line++;
	}
	fraiche[len_t1] = NULL;
	fraiche = verif_dir_double(fraiche);
	return (fraiche);
}
/*
int 		verif_tab_doublons(char **ref)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, line2, 1);
	if (!ref)
		return (1);	
	while (ref[line])
	{
		while (ref[line2])
		{
			if (!ft_strcmp(ref[line], ref[line2]))
				return (0);
			line2++;
		}
		line++;
		line2 = line + 1;
	}
	return (1);
}*/

char 		**flag_R(t_store *store, int nb_dir)
{
	FT_INIT(char **, argv, NULL);
	FT_INIT(t_file*, tmp, store->start_list);
	if (!nb_dir)
	{
		ft_putstr("NO DIR\n");
		return (NULL);
	}
	argv = (char **)malloc(sizeof(char *) * nb_dir);
	nb_dir = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->rights, 'd'))
		{
			argv[nb_dir] = ft_strdup(tmp->absolute_path);
			if (argv[nb_dir][ft_strlen(argv[nb_dir]) - 1] != '/')
				argv[nb_dir] = ft_strjoin(argv[nb_dir], "/");
			argv[nb_dir + 1] = NULL;
			nb_dir++;
		}
		tmp = tmp->next;
	}
	return (argv);
}
