#include "../includes/lem-in.h"

char 		**del_tab_line(char **tab, int line)
{
	while (tab[line])
	{
		tab[line] = tab[line + 1];
		line++;
	}
	if (tab[line - 1])
		ft_memdel((void*)tab[line - 1]);
	return (tab);
}

int			verif_deleted_line(char *line, char *line2, t_check *check)
{
	FT_INIT(char*, last_cell, NULL);
	FT_INIT(int, nb_arg, 0);
	last_cell = ft_strdup(ft_strrnchr(line, ' ', nb_arg));
	while (last_cell)
	{
		if (last_cell && ft_strcmp(last_cell, check->end_cell)
		&& ft_strstr(line2, last_cell))
			return (1);
		nb_arg++;
		ft_memdel((void*)&last_cell);
		if (!ft_strrnchr(line, ' ', nb_arg))
			break;
		last_cell = ft_strdup(ft_strrnchr(line, ' ', nb_arg));
	}
	return (0);
}

char 		**del_second_par(char **tab, t_check *check)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, ref, ft_len_tab(tab) - 1);
	FT_INIT(int, line2, ref);
	while (line2 > 0 && tab[line2])
	{
		while (tab[line] && tab[line2])
		{
			if (!ft_strrnchr(tab[line], ' ', 0))
					break;
			if (ft_strcmp(tab[line], tab[line2]) && 
			verif_deleted_line(tab[line], tab[line2], check))
			{
				del_tab_line(tab, line2);
				MULTI(line2, ref, ref - 1);
			}
			line++;
		}
		line2 = line > 0 ? (line2 - 1) : ref;
		line = 0;
	}
	return (tab);
}

char 		**del_over_road(char **tab, t_check *check)
{
	FT_INIT(int, line, 0);
	FT_INIT(int, ref, ft_len_tab(tab) - 1);
	FT_INIT(int, line2, ref);
	while (line2 > 0 && tab[line2])
	{
		while (tab[line2] && tab[line])
		{
			if ((ft_strcmp(first(tab[line]), check->end_cell) 
			&& ft_strcmp(first(tab[line2]), check->end_cell)
			&& ft_strcmp(first(tab[line2]), first(tab[line]))
			&& ft_strstr(tab[line2], first(tab[line]))) || (line2 != line 
			&& !ft_strcmp(first(tab[line2]), first(tab[line]))))
			{
					del_tab_line(tab, line2);
					MULTI(line2, ref, ref - 1);
					line = 0;
					break;
			}
			else
				line++;
		}
		line2 = line > 0 ? (line2 - 1) : ref;
		line = 0;
	}
	return (del_second_par(tab, check));
}