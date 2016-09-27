/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:46:06 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/05 17:46:07 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(ret = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
