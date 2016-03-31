/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:36:00 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:49:12 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		e;

	if (s == NULL || f == NULL)
		return (NULL);
	fraiche = NULL;
	e = 0;
	if (!(fraiche = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[e])
	{
		fraiche[e] = f(s[e]);
		e++;
	}
	fraiche[e] = '\0';
	return (fraiche);
}
