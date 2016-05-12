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
//			if (ft_strcmp(s1->name, s2->name) < 0)
//				return (1);
		}
		else if (ft_strcmp_abs(s1->name, s2->name) > 0)
				return (1);
//		else if (ft_strcmp(s1->name, s2->name) > 0)
//				return (1);
	}
	else
	{
//		if (ft_strcmp(s1->name, s2->name) > 0)
//			return (1);
		if (ft_strcmp_abs(s1->name, s2->name) > 0)
			return (1);
	}
	return (0);
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

t_file 		*sort_list(t_file *files, t_store *store)
{
	FT_INIT(t_file*, after, files);
	FT_INIT(t_file*, before, files);
	FT_INIT(t_file*, tmp, NULL);
	while (after && after->next)
	{
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
	return (files);
}