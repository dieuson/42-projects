/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:31:59 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/07 15:40:50 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fraiche;
	unsigned	i;
	int			e;

	fraiche = NULL;
	if (s == NULL)
		return (NULL);
	e = 0;
	i = start;
	fraiche = ft_strnew(len);
	if (fraiche == NULL)
		return (NULL);
	while (i < start + len)
		fraiche[e++] = s[i++];
	fraiche[e] = '\0';
	return (fraiche);
}
