/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:41:09 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:55:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*temp;

	if (len > 0)
	{
		temp = ft_strnew(len);
		ft_memcpy(temp, (char*)src, len);
		ft_memcpy(dst, temp, len);
		free(temp);
		return (dst);
	}
	return (NULL);
}
