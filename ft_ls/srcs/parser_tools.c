/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:45:31 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/31 15:45:31 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			*reset_int_tab(int *tab, int len)
{
	int		line;

	line = 0;
	while (tab && len && line < len)
	{
		tab[line] = 0;
		line++;
	}
	return (tab);
}

int			*create_int_tab(int len)
{
	int		*fraiche;

	fraiche = (int*)malloc(sizeof(int) * len);
	fraiche = reset_int_tab(fraiche, len);
	return (fraiche);
}

int			len_str(char *str)
{
	FT_INIT(int, len, 0);
	while (str && str[len])
		len++;
	return (len);
}

int			len_nb(int nb)
{
	FT_INIT(int, len, 0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
