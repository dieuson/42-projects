/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:53:01 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/01 10:57:43 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				dest_len;

	dest_len = 0;
	i = 0;
	while (s1[dest_len])
	{
		dest_len++;
	}
	while (s2[i] && i < n)
	{
		s1[dest_len + i] = s2[i];
		i++;
	}
	s1[dest_len + i] = '\0';
	return (s1);
}
