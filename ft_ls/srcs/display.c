#include "../includes/ft_ls.h"

void 		print_date(char **date)
{
	ft_printf("%5s %5s %5s ", date[0], date[1], date[2]);
}

void 		print_data(t_store *store)
{
	FT_INIT(t_file*, tmp, store->start_list);
	if (store->flags && ft_strstr(store->flags, "R"))
	{
		if (!ft_strcmp(tmp->path, "./"))
			ft_printf(".:	\n");
		else
			ft_printf("%s\n", tmp->path);
	}
	while (tmp)
	{
		if (store->flags && ft_strchr(store->flags, 'l'))
		{
			ft_printf("%s ", tmp->rights);
			ft_printf("%3d ", tmp->link);
			ft_printf("%5s ", tmp->owner);
			ft_printf("%5s", tmp->owner_grp);
			ft_printf("%7d", tmp->size);
			print_date(tmp->date);
		}
		ft_printf("%s\n", tmp->name);
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
