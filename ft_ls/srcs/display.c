/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:20:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/10 11:48:31 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*set_sentence(int len, char *flag)
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

static void		print_l(t_file *tmp, char *flags, int *len_display)
{
	if (!tmp)
		return ;
	FT_INIT(char *, del, NULL);
	if (flags && (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')))
	{
		ft_printf("%10s ", tmp->rights);
		ft_printf(del = set_sentence((len_display)[1], "d "), tmp->link);
		ft_strdel(&del);
		ft_printf(del = set_sentence((len_display)[2], "s "), tmp->owner);
		ft_strdel(&del);
		if (!flags || (flags && !ft_strchr(flags, 'g')))
			ft_printf(del = set_sentence((len_display)[3] + 1, "s "),
			tmp->owner_grp);
		ft_strdel(&del);
		ft_printf(del = set_sentence((len_display)[4] + 2, "d "), tmp->size);
		ft_strdel(&del);
		ft_printf(del = set_sentence((len_display)[5], "s "), (tmp->date)[0]);
		ft_strdel(&del);
		ft_printf(del = set_sentence((len_display)[6], "s "), (tmp->date)[1]);
		ft_strdel(&del);
		ft_printf(del = set_sentence((len_display)[7], "s "), (tmp->date)[2]);
		ft_strdel(&del);
	}
	ft_printf(("%-s"), tmp->name);
	ft_strdel(&del);
}

static char		*put_color(t_file *tmp, char *flags, int position)
{
	struct stat infos;
	ssize_t r;

	FT_INIT(char*, link_name, NULL);
	if (!position && flags && ft_strchr(flags, 'l')
		&& ft_strchr(tmp->rights, 'l'))
	{
		lstat(tmp->absolute_path, &infos);
		link_name = ft_strnew(infos.st_size + 1);
		r = readlink(tmp->absolute_path, link_name, infos.st_size + 1);
		link_name[r] = '\0';
	}
	if (!tmp || !flags || (flags && !ft_strchr(flags, 'c')))
		return (link_name);
	if (!position && (tmp->rights)[0] == 'd')
		ft_printf("\033[31m");
	else if (!position && (tmp->rights)[0] == 'l')
		ft_printf("\033[32m");
	if (position && ((tmp->rights)[0] == 'd' || (tmp->rights)[0] == 'l'))
		ft_printf("\033[0m");
	return (link_name);
}

static void		p_path(t_file *tmp, char *path, char *flags, t_store *store)
{
	if (tmp && store->type && ft_strcmp(tmp->absolute_path, tmp->name) &&
	(store->nb_directories > 1 || (store->nb_directories && store->nb_files)))
	{
		if (!ft_strcmp(tmp->path, "./"))
			ft_printf("%s:\n", ".");
		else if (!ft_strcmp(tmp->path, "../"))
			ft_printf("%s:\n", "..");
		else
			ft_printf("%s:\n", tmp->path);
		if (flags && (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')))
			ft_printf("total %d\n", tmp->nb_blocks);
	}
	else if (!store->type && ft_strcmp(tmp->path, path) &&
	ft_strcmp(tmp->absolute_path, tmp->name))
	{
		if (!ft_strcmp(tmp->path, "./"))
			ft_printf("\n%s:\n", ".");
		else if (!ft_strcmp(tmp->path, "../"))
			ft_printf("\n%s:\n", "..");
		else
			ft_printf("\n%s:\n", tmp->path);
		if (flags && (ft_strchr(flags, 'l') || ft_strchr(flags, 'g')))
			ft_printf("total %d\n", tmp->nb_blocks);
	}
}

void			print_data(t_store *store)
{
	FT_INIT(t_file*, tmp, store->start_list);
	FT_INIT(char*, path, tmp->path);
	FT_INIT(char*, link_name, NULL);
	FT_INIT(int*, len_display, tmp->display);
	while (tmp)
	{
		if (tmp->display && len_display)
			free_int_tab(&len_display, 9);
		if (tmp->display)
			len_display = tmp->display;
		p_path(tmp, path, store->flags, store);
		store->type = 0;
		link_name = put_color(tmp, store->flags, 0);
		print_l(tmp, store->flags, len_display);
		if (store->flags && ft_strchr(store->flags, 'l')
		&& ft_strchr(tmp->rights, 'l') && link_name)
		{
			ft_printf(" -> %s\n", link_name);
			ft_strdel(&link_name);
		}
		else
			ft_putendl("");
		put_color(tmp, store->flags, 1);
		path = tmp->path;
		tmp = tmp->next;
	}
}
