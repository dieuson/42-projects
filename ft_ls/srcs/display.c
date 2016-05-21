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
	to_del = c_len;
	c_len = ft_strjoin(c_len, flag);
	ft_strdel(&to_del);
	return (c_len);
}
/*
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
}*/

static void		print_l(t_file *tmp, char *flags, int *len_display)
{
	if (!tmp)
		return ;
	FT_INIT(char *, to_del, NULL);
	if (flags && (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')))
	{
		ft_printf("%10s ", tmp->rights);
		ft_printf(to_del = set_sentence((len_display)[1], "d "), tmp->link);
		ft_strdel(&to_del);
		ft_printf(to_del = set_sentence((len_display)[3] + 1, "s "), tmp->owner_grp);
		ft_strdel(&to_del);
		if (!flags || (flags && !ft_strchr(flags, 'g')))
			ft_printf(to_del = set_sentence((len_display)[2], "s "), tmp->owner);
		ft_strdel(&to_del);
		ft_printf(to_del = set_sentence((len_display)[4] + 2, "d "), tmp->size);
		ft_strdel(&to_del);
		ft_printf(to_del = set_sentence((len_display)[5], "s "), (tmp->date)[0]);
		ft_strdel(&to_del);
		ft_printf(to_del = set_sentence((len_display)[6], "s "), (tmp->date)[1]);
		ft_strdel(&to_del);
		ft_printf(to_del = set_sentence((len_display)[7], "s "), (tmp->date)[2]);
		ft_strdel(&to_del);
	}
	ft_printf(to_del = set_sentence(len_display[8], "-s"), tmp->name);
	ft_strdel(&to_del);
}

static void 	put_color(t_file *tmp, char *flags, int position)
{
	if (!tmp || !flags || (flags && !ft_strchr(flags, 'c')))
		return ;
	if (!position && (tmp->rights)[0] == 'd')
		ft_printf("\033[31m");
	else if (!position && (tmp->rights)[0] == 'l')
			ft_printf("\033[32m");
	if (position && ((tmp->rights)[0] == 'd' || (tmp->rights)[0] == 'l'))
		ft_printf("\033[0m");
}

void			print_data(t_store *store)
{
	FT_INIT(t_file*, tmp, store->start_list);
	FT_INIT(char*, path, tmp->path);
	FT_INIT(int*, len_display, tmp->display);
//	ft_printf("start fisplay\n");
	while (tmp)
	{
		if (tmp->display && len_display)
			free_int_tab(&len_display, 9);
		if (tmp->display)
			len_display = tmp->display;
		if ((tmp->path && path && ft_strcmp(tmp->path, path)  && ft_strcmp(tmp->absolute_path, tmp->name)))
		{
			if (ft_printf)
			ft_printf("%s:\n", tmp->path);
			if (store->flags && (ft_strchr(store->flags, 'l') || ft_strchr(store->flags, 'g')))
				ft_printf("total %d\n", tmp->nb_blocks);			
		}
		put_color(tmp, store->flags, 0);
		print_l(tmp, store->flags, len_display);
		if (store->flags && ft_strchr(store->flags, 'l') && ft_strchr(tmp->rights, 'l'))
			ft_printf(" -> private/%s\n", tmp->private);
		else
			ft_putendl("");
		put_color(tmp, store->flags, 1);
		path = tmp->path;
		tmp = tmp->next;
	}
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

void			print_list(t_file *file)
{
	t_file *tmp;

	tmp = file;
	while (tmp)
	{
		ft_printf("tmp->name =%s, absolute->path =%s, \n", tmp->name, tmp->absolute_path);
		tmp = tmp->next;
	}
	ft_printf("\n");
}