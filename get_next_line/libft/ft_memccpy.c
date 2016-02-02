/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:08:46 by dvirgile          #+#    #+#             */
/*   Updated: 2015/11/30 14:38:24 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*temp;
	char			*temp2;

	i = 0;
	temp2 = (char *)dst;
	temp = (char *)src;
	while (i < n)
	{
		temp2[i] = temp[i];
		if (temp2[i] == (char)c)
		{
			dst = (void *)temp2;
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
