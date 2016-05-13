#include "../includes/ft_ls.h"

void 		print_date(char **date, char **get_len)
{
	ft_printf(get_len[5], date[0]);
	ft_printf(get_len[6], date[1]);
	ft_printf(get_len[7], date[2]);
}

char 		*set_sentence(int len, char *flag)
{
	FT_INIT(char *, c_len, ft_itoa(len));
	FT_INIT(char *, to_del, c_len);
	c_len = ft_strjoin("%", c_len);
	ft_strdel(&to_del);
	to_del = c_len;
	c_len = ft_strjoin(c_len, flag);
	ft_strdel(&to_del);
	return (c_len);
}

char 		**set_len_disp(int *display, char **tab)
{
	tab[0] = set_sentence(display[0], "s ");
	tab[1] = set_sentence(display[1], "d ");
	tab[2] = set_sentence(display[2], "s ");
	tab[3] = set_sentence(display[3], "s ");
	tab[4] = set_sentence(display[4], "d ");
	tab[5] = set_sentence(display[5], "s ");
	tab[6] = set_sentence(display[6], "s ");
	tab[7] = set_sentence(display[7], "s ");
	tab[8] = set_sentence(display[8], "-s\n");
	return (tab);
}

void 		print_data(t_store *store)
{
	FT_INIT(char **, get_len, NULL);
	FT_INIT(t_file*, tmp, store->start_list);
	if (store->flags && ft_strstr(store->flags, "R"))
	{
		if (!ft_strcmp(tmp->path, "./"))
			ft_printf(".:	\n");
		else
			ft_printf("%s\n", tmp->path);
	}
	get_len = (char**)malloc(sizeof(char*) * 7);
	get_len = set_len_disp(tmp->display, get_len);
//	ft_printf("display =%d,\n", get_len[0]);
	while (tmp)
	{
//		if (tmp->display)
		if (get_len && store->flags && ft_strchr(store->flags, 'l'))
		{
			ft_printf(get_len[0], tmp->rights);
			ft_printf(get_len[1], tmp->link);
			ft_printf(get_len[2], tmp->owner);
			ft_printf(get_len[3], tmp->owner_grp);
			ft_printf(get_len[4], tmp->size);
//			print_date(tmp->date, get_len);
			ft_printf(get_len[5], (tmp->date)[0]);
			ft_printf(get_len[6], (tmp->date)[1]);
			ft_printf(get_len[7], (tmp->date)[2]);
		}
		ft_printf(get_len[8], tmp->name);
	if (tmp->next && ft_strcmp(tmp->path, (tmp->next)->path))
		ft_printf("\n%s:\n", (tmp->next)->path);
		tmp = tmp->next;
	}
}

void 		print_list(t_store *store)
{
	t_file *tmp;

	tmp = store->start_list;
	while (tmp)
	{
		ft_printf("tmp->name =%s,\n", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void		print_simple_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab && tab[ligne])
	{
		ft_putstr(tab[ligne]);
		ft_putstr("\n");
		ligne++;
	}
}
