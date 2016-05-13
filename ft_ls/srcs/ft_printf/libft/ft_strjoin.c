/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:45:16 by dvirgile          #+#    #+#             */
/*   Updated: 2015/12/03 17:36:24 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fraiche = (char *)malloc(sizeof(fraiche) * ft_strlen(s1) + ft_strlen(s2));
	if (fraiche == NULL)
		return (NULL);
	ft_bzero(fraiche, (ft_strlen(s1) + ft_strlen(s2)));
	fraiche = ft_strcat(fraiche, s1);
	fraiche = ft_strcat(fraiche, s2);
	return (fraiche);
}
