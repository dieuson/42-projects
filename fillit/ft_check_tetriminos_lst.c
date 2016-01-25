/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:45:08 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/25 08:45:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstadd_bottom(t_list **alst, t_list *new)
{
	if (alst != NULL && *alst != NULL && new != NULL)
	{
		while ((*alst)->next != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
	}
}

void		ft_print_list(t_list **alst)
{
	t_list	*tmp;

	tmp = *alst;
	if (alst != NULL && *alst != NULL)
	{
		if (ft_strlen((char*)tmp->content) < 20)
			tmp = tmp->next;
		while (tmp->next != NULL)
		{
			ft_putendl((char*)tmp->content);
			tmp = tmp->next;
		}
		ft_putendl((char*)tmp->content);
	}
}

t_list		*make_lst(char *str, int i)
{
	int		j;
	char	buf[21];
	t_list	*list;
	t_list	*tmp;
	t_list	*list_ptr;

	j = 0;
	ft_bzero(buf, 21);
	list = ft_lstnew(buf, (sizeof(char) * 21));
	tmp = list;
	list_ptr = list;
	while (str[i])
	{
		j = 0;
		while (j < 20)
			buf[j++] = str[i++];
		buf[j] = '\0';
		tmp = ft_lstnew(buf, (sizeof(char) * 21));
		ft_lstadd_bottom(&list, tmp);
		list = list->next;
		i++;
	}
	return (list_ptr);
}

int			iter_buf(char *buf)
{
	int		i;
	int		diese;
	int		check;

	i = -1;
	diese = 0;
	check = 0;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			diese++;
			if (buf[i + 1] == '#' && (i + 1) < 22)
				check++;
			if (buf[i - 1] == '#' && (i - 1) >= 0)
				check++;
			if (buf[i + 5] == '#' && (i + 5) < 22)
				check++;
			if (buf[i - 5] == '#' && (i - 5) >= 0)
				check++;
		}
		if (diese == 4 && check >= 6 && check <= 8)
			return (0);
	}
	return (1);
}

int			ft_check_tetriminos_lst(t_list **list)
{
	char	*buf;
	t_list	*tmp;

	tmp = *list;
	if (ft_strlen((char*)tmp->content) < 20)
		tmp = tmp->next;
	while (tmp->next != NULL)
	{
		buf = ft_strdup((char*)tmp->content);
		if (iter_buf(buf) == 0)
			tmp = tmp->next;
		else
			return (1);
	}
	buf = ft_strdup((char*)tmp->content);
	if (iter_buf(buf) == 0)
		return (0);
	else
		return (1);
}
