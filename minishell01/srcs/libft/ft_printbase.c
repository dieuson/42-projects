/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 18:52:31 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/12 18:52:34 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_printbase(unsigned char n, int base)
{
	if (base > 0 && base <= 10)
	{
		if (n >= base)
			ft_printbase((n / base), base);
		ft_putchar((n % base) + '0');
	}
}
