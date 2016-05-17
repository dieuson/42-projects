/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:20:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/16 14:20:36 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*set_sentence(int len, char *flag)
{
	FT_INIT(char *, c_len, ft_itoa(len));
	FT_INIT(char *, to_del, c_len);
	c_len = ft_strjoin("%", c_len);
	ft_strdel(&to_del);
	c_len = ft_strjoin(c_len, flag);
	return (c_len);
}

static void		print_l(t_file *tmp, char *flags)
{
	if (!tmp)
		return ;
	ft_printf("%10s ", tmp->rights);
	ft_printf(set_sentence((tmp->display)[1], "d "), tmp->link);
	ft_printf(set_sentence((tmp->display)[2], "s "), tmp->owner);
	if (!flags || (flags && !ft_strchr(flags, 'g')))
		ft_printf(set_sentence((tmp->display)[3] + 1, "s "), tmp->owner_grp);
	ft_printf(set_sentence((tmp->display)[4] + 2, "d "), tmp->size);
	ft_printf(set_sentence((tmp->display)[5], "s "), (tmp->date)[0]);
	ft_printf(set_sentence((tmp->display)[6], "s "), (tmp->date)[1]);
	ft_printf(set_sentence((tmp->display)[7], "s "), (tmp->date)[2]);
}

void			print_data(t_store *store, int ref)
{
	FT_INIT(t_file*, tmp, store->start_list);
	if (store->flags && ft_strchr(store->flags, 'R'))
	{
		if (!ft_strcmp(tmp->path, "./"))
			ft_printf(".:	\n");
		else
			ft_printf("%s\n", tmp->path);
	}
	if (ref && store->flags && ft_strchr(store->flags, 'l'))
		ft_printf("total %d\n", tmp->nb_blocks);
	while (tmp)
	{
		if (store->flags && ft_strchr(store->flags, 'l'))
			print_l(tmp, store->flags);
		ft_printf(set_sentence((tmp->display)[8], "-s\n"), tmp->name);
		if (tmp->next && ft_strcmp(tmp->path, (tmp->next)->path))
		{
			ft_printf("\n%s:\n", (tmp->next)->path);
			if (store->flags && ft_strchr(store->flags, 'l'))
				ft_printf("total %d\n", (tmp->next)->nb_blocks);
		}
		tmp = tmp->next;
	}
}

void			print_list(t_store *store)
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