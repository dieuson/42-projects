/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:18:41 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/02 12:04:28 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isascii(int c)
{
	if (c < 128 && c >= 0)
		return (1);
	return (0);
}
