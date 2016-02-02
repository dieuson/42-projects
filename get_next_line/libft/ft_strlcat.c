/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:43:26 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:38:01 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	e;

	e = 0;
	i = 0;
	dest_len = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
		dest_len++;
	}
	while (src[e] != '\0' && i < size - 1)
	{
		dst[i] = src[e];
		i++;
		e++;
	}
	if (i < size)
		dst[i] = '\0';
	return (dest_len + ft_strlen(src));
}
