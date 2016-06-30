/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:54:06 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/12 18:54:08 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_putwstr(wchar_t *str, int write)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] && str != NULL)
	{
		len += ft_putwchar(str[i], write);
		i++;
	}
	return (len);
}
