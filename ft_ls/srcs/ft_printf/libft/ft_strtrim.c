/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:35:49 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:57:42 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*s2;
	int		i;
	int		e;
	int		l;

	l = 0;
	e = 0;
	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (!(s2 = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	while (e <= i)
		s2[l++] = s[e++];
	s2[l] = '\0';
	return (s2);
}
