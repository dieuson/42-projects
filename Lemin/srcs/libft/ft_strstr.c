/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:31:10 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/03 17:33:59 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int length;
	int e;

	e = 0;
	length = ft_strlen(s2);
	i = 0;
	if (length == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s1[i + e] == s2[e])
		{
			if (e == length - 1)
				return ((char*)(s1 + i));
			e++;
		}
		e = 0;
		i++;
	}
	return (NULL);
}
