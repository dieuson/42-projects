/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:53:14 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/03 17:41:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fraiche;
	t_list *poubelle;
	t_list *stock;

	if (!lst || !f)
		return (NULL);
	poubelle = f(lst);
	fraiche = ft_lstnew(poubelle->content, poubelle->content_size);
	stock = fraiche;
	lst = lst->next;
	while (lst)
	{
		poubelle = f(lst);
		stock->next = ft_lstnew(poubelle->content, poubelle->content_size);
		lst = lst->next;
		stock = stock->next;
	}
	return (fraiche);
}
