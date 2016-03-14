/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:24:41 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/12 19:24:44 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ftp_putbase(uintmax_t n, uint32_t base, uint8_t flag, t_docker *data)
{
	if (base > 0 && base <= 10)
	{
		if (base == 8 && data->dieze == 1)
		{
			if (n == 0 && !data->dot)
				return (ftp_putchar('0'));
			data->len += !data->precision ? ftp_putchar('0') : 0;
			data->dieze = 0;
		}
		n >= base ? ftp_putbase((n / base), base, flag, data) : 0;
		ft_putchar((n % base) + '0');
	}
	else if (base == 16)
	{
		if (n != 0 && data->dieze == 1 && !data->zero && !data->dot)
			data->len += (ftp_putchar('0') + ftp_putchar(flag + 23));
		data->dieze = 0;
		if (n >= 16)
		{
			ftp_putbase((n / 16), base, flag, data);
			n %= 16;
		}
		ft_putchar((n % 16) >= 10 ? (n % 10) + flag : (n % 16) + '0');
	}
	return (0);
}
