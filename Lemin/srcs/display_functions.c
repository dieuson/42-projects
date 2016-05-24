/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:45:17 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/24 11:28:25 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void				print_bonus(t_check *check, char **tab, t_ref *ref, int i)
{
	if (!check->flags)
		return ;
	FT_INIT(int, nb_loops, 0);
	ref->nb_ants_ref = 0;
	if (ft_strchr(check->flags, 'm'))
	{
		ft_putstr("nb movements :");
		ft_putnbr(i);
		ft_putendl("");
	}
	if (ft_strchr(check->flags, 'r'))
	{
		ft_putendl("roads :");
		while (nb_loops <= calc_last_ligne(check, ref))
		{
			ft_putendl(tab[nb_loops]);
			nb_loops++;
		}
	}
}

t_cells				*find_ant_nb(int nb, t_check *check)
{
	t_cells	*tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->someone && ft_atoi(ft_strrchr(tmp->someone,
		check->ant_name[ft_strlen(check->ant_name) - 1]) + 1) == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static char			*join_route(char *tmp, char *ref)
{
	FT_INIT(char *, to_del, tmp);
	FT_INIT(int, i, ft_atoi(ft_strchr(tmp, '-') - 1));
	if (i < 8)
		tmp = ft_strjoin("\033[", ft_itoa(90 + i));
	else
		tmp = ft_strjoin("\033[", ft_itoa(30 + (i - 8)));
	to_del = tmp;
	tmp = ft_strjoin(tmp, "m");
	ft_strdel(&to_del);
	to_del = tmp;
	tmp = ft_strjoin(tmp, ref);
	ft_strdel(&to_del);
	to_del = tmp;
	tmp = ft_strjoin(tmp, "\033[0m");
	ft_strdel(&to_del);
	to_del = tmp;
	tmp = ft_strjoin(tmp, " ");
	ft_strdel(&to_del);
	return (tmp);
}

int					print_shining_ants(t_check *check, char *route)
{
	if (!check->flags || !route)
		return (0);
	if (!ft_strchr(check->flags, 'c'))
		return (0);
	FT_INIT(char **, tmp, ft_strsplit(route, ' '));
	FT_INIT(int, line, 0);
	FT_INIT(char *, to_del, NULL);
	while (tmp && tmp[line])
	{
		to_del = tmp[line];
		tmp[line] = join_route(tmp[line], tmp[line]);
		ft_strdel(&to_del);
		ft_putstr(tmp[line]);
		line++;
	}
	ft_putendl("");
	return (1);
}

void				print_route(char **route, char *someone, char *name)
{
	char	*to_del;

	if (*route)
	{
		to_del = *route;
		*route = ft_strjoin(*route, " ");
		ft_strdel(&to_del);
		to_del = *route;
		*route = ft_strjoin(*route, someone);
		ft_strdel(&to_del);
	}
	else if (!*route)
		*route = ft_strdup(someone);
	to_del = *route;
	*route = ft_strjoin(*route, "-");
	ft_strdel(&to_del);
	*route = ft_strjoin(*route, name);
}
