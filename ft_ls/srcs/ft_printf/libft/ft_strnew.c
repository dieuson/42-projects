/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:38:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:49:34 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	char			*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	bzero(str, (size + 1));
	return (str);
}
