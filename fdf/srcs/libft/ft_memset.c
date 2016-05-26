/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:07:13 by dvirgile          #+#    #+#             */
/*   Updated: 2015/11/26 16:04:27 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*box;

	i = 0;
	box = (char *)s;
	while (i < n)
	{
		box[i] = c;
		i++;
	}
	s = (void *)box;
	return (s);
}
