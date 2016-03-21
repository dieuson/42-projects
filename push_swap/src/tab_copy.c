/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:16:50 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 15:17:22 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tab_copy(int **src, int **dest, int len_a, int len_b)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	FT_INIT(int, len, len_a);
	while (i < 2)
	{
		while (e < len)
		{
			dest[i][e] = src[i][e];
			e++;
		}
		len = len_b;
		e = 0;
		i++;
	}
}
