/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:51:41 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/12 18:51:44 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_list(t_list **alst)
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
