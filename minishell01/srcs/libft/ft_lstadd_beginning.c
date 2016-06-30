/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_beginning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:32:35 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/12 19:32:35 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstadd_beginning(t_list **alst, t_list *new)
{
	if (alst && *alst)
	{
		new->next = *alst;
		*alst = new;
	}
}
