/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:15:34 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/02 11:22:10 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	e;

	e = 0;
	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		while (s1[i + e] == s2[e] && (i + e) < n)
		{
			if (e == (unsigned int)ft_strlen(s2) - 1)
				return ((char*)(s1 + i));
			e++;
		}
		e = 0;
		i++;
	}
	return (NULL);
}
