#include "../includes/ft_ls.h"

static int		compare_date(t_file *cell1, t_file *cell2)
{
	int dif;

	dif = cell1->time_estamp - cell2->time_estamp;
	return (dif);
}

static int 		compare(t_file *s1, t_file *s2, t_store *store)
{
	if (store->flags)
	{
		if (ft_strchr(store->flags, 't'))
		{
			if (ft_strchr(store->flags, 'r') && compare_date(s1, s2) > 0)
				return (1);
			else if (!ft_strchr(store->flags, 'r') && compare_date(s1, s2) < 0)
				return (1);
		}
		else if (ft_strchr(store->flags, 'f'))
			return (0);
		else if (ft_strchr(store->flags, 'r') && ft_strcmp(s1->name, s2->name) < 0)
			return (1);
		else if (!ft_strchr(store->flags, 'r') && ft_strcmp(s1->name, s2->name) > 0)
				return (1);
	}
	else
	{
		if (ft_strcmp(s1->name, s2->name) > 0)
			return (1);
	}
	return (0);
}

int 		*compare_len(char *flags, t_file *files, int *tab)
{
	if (flags && ft_strchr(flags, 'l'))
	{
		tab[0] = len_str(files->rights) > tab[0] ? len_str(files->rights) : tab[0];
		tab[1] = len_nb(files->link) > tab[1] ? len_nb(files->link) : tab[1];
		tab[2] = len_str(files->owner) > tab[2] ? len_str(files->owner) : tab[2];
		tab[3] = len_str(files->owner_grp) > tab[3] ? len_str(files->owner_grp) : tab[3];
		tab[4] = len_nb(files->size) > tab[4] ? len_nb(files->size) : tab[4];
		tab[5] = len_str(files->date[0]) > tab[5] ? len_str(files->date[0]) : tab[5];
		tab[6] = len_str(files->date[1]) > tab[6] ? len_str(files->date[1]) : tab[6];
		tab[7] = len_str(files->date[2]) > tab[7] ? len_str(files->date[2]) : tab[7];
	}
	tab[8] = len_str(files->name) > tab[8] ? len_str(files->name) : tab[8];
	return (tab);
}

t_file 		*sort_list(t_file *files, t_store *store)
{
	FT_INIT(t_file*, after, files);
	FT_INIT(t_file*, before, files);
	FT_INIT(t_file*, tmp, NULL);

//	ft_putstr("test2\n");
	while (after && after->next)
	{
//		ft_printf("after->name =%s, 	before->name =%s,\n", after->name, before->name);
		if (compare(after, after->next, store) > 0)
		{
			files = (after == files) ? after->next : files;
			before->next = after->next;
			tmp = (after->next)->next;
			(after->next)->next = after;
			after->next = tmp;
			MULTI(after, before, files);
		}
		else
		{
			before = after;
			after = after->next;
		}
	}
//	print_list_ls(files);
	return(files);
}