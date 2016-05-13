/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:27:12 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/02 14:08:12 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	char				*temp;
	char				*temp2;

	i = 0;
	temp2 = dst;
	temp = (char*)src;
	if (n > 0)
	{
		while (i < n)
		{
			temp2[i] = temp[i];
			i++;
		}
	}
	return (dst);
}
