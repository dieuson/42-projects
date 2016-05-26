/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:00:07 by dvirgile          #+#    #+#             */
/*   Updated: 2015/11/27 15:17:57 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void				*ft_memalloc(size_t size)
{
	void			*fraiche;
	char			*b;
	unsigned int	i;

	i = 0;
	fraiche = malloc(size);
	if (fraiche == NULL)
		return (NULL);
	b = (char *)fraiche;
	while (i < size)
	{
		b[i] = 0;
		i++;
	}
	fraiche = (void *)b;
	return (fraiche);
}
