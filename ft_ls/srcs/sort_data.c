/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:47:46 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/31 15:47:48 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		compare_date(t_file *cell1, t_file *cell2)
{
	int dif;

	dif = cell1->time_estamp - cell2->time_estamp;
	return (dif);
}

static int		compare(t_file *s1, t_file *s2, char *flags)
{
	if (flags)
	{
		if (flags[3] == 't' || (flags[3] == 't' && flags[5] == 'u')
									|| (flags[0] == '0' && flags[5] == 'u'))
		{
			if (ft_strchr(flags, 'r') && compare_date(s1, s2) > 0)
				return (1);
			else if (!ft_strchr(flags, 'r') && compare_date(s1, s2) < 0)
				return (1);
		}
		else if (ft_strchr(flags, 'f'))
			return (0);
		else if (ft_strchr(flags, 'r') && ft_strcmp(s1->name, s2->name) < 0)
			return (1);
		else if (!ft_strchr(flags, 'r') && ft_strcmp(s1->name, s2->name) > 0)
			return (1);
	}
	else
	{
		if (ft_strcmp(s1->name, s2->name) > 0)
			return (1);
	}
	return (0);
}

int				*compare_len(char *flags, t_file *files, int *tab)
{
	if (flags && (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')))
	{
		tab[0] = len_str(files->rights) > tab[0] ?
									len_str(files->rights) : tab[0];
		tab[1] = len_nb(files->link) > tab[1] ?
									len_nb(files->link) : tab[1];
		tab[2] = len_str(files->owner) > tab[2] ?
									len_str(files->owner) : tab[2];
		tab[3] = len_str(files->owner_grp) > tab[3] ?
									len_str(files->owner_grp) : tab[3];
		tab[4] = len_nb(files->size) > tab[4] ?
									len_nb(files->size) : tab[4];
		tab[5] = len_str(files->date[0]) > tab[5] ?
									len_str(files->date[0]) : tab[5];
		tab[6] = len_str(files->date[1]) > tab[6] ?
									len_str(files->date[1]) : tab[6];
		tab[7] = len_str(files->date[2]) > tab[7] ?
									len_str(files->date[2]) : tab[7];
	}
	tab[8] = len_str(files->name) > tab[8] ? len_str(files->name) : tab[8];
	return (tab);
}

t_file			*sort_list(t_file *files, t_store *store)
{
	FT_INIT(t_file*, after, files);
	FT_INIT(t_file*, before, files);
	FT_INIT(t_file*, tmp, NULL);
	while (after && after->next)
	{
		if (compare(after, after->next, store->flags) > 0)
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
