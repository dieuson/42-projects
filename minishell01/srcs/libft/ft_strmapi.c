/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:18:31 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:49:21 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fraiche;
	int		e;

	fraiche = NULL;
	if (s == NULL || f == NULL)
		return (NULL);
	e = 0;
	if (!(fraiche = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[e])
	{
		fraiche[e] = f(e, s[e]);
		e++;
	}
	return (fraiche);
}
