/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:40:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/05 14:21:32 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

int			ftp_less(int len_str, char *str, int choice, int dimension)
{
	unsigned int nb_spaces;

//	ft_putstr("\ndimension\n");
//	ft_putnbr(dimension);
//	ft_putstr("\n\n");
	nb_spaces = dimension - ft_strlen(str);
	if (choice == -1)
		write(1, str, ft_strlen(str));
	else if (choice == 0)
		return (len_str += ftp_putstr((uint8_t *)str));
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, " ", 1);
			nb_spaces --;
			len_str++;
			}
	}
	if (choice == 1)
		write(1, str, ft_strlen(str));
	return (len_str + ft_strlen(str));
}

int			add_spaces(int nb_spaces, int len)
{
	if (nb_spaces > 0)
	{
		while (nb_spaces > 0)
		{
			write(1, " ", 1);
			nb_spaces --;
			len++;
		}
	}
	return (len);
}

int					ftp_dot(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < ft_strlen(str) && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int			ftp_less_test(int width, int precision, char *str, int len, int who)
{
//	unsigned int nb_spaces;

//	ft_putstr("\ndimension\n");
//	ft_putnbr(dimension);
//	ft_putstr("\n\n");
//	nb_spaces = dimension - ft_strlen(str);
	if (who == -1)				 // Avec une '-'
	{
		len += ftp_putstr((uint8_t *)str);
		len = add_spaces((width - ft_strlen(str)), len);
	}
	else if (who == 0) 			// Avec un '.'
	{
//		ft_putstr("\n\n\ttest\n\n");
		len += ftp_dot(str, precision);
	}
	else if (who == 1) 			// Avec un '-' et un '.'
	{
		len += ftp_dot(str, precision);
		len = add_spaces((width - ft_strlen(str)), len);
	}
	else if (who == 2) 			// Avec un 'nombre' et un '.'
	{
		len = add_spaces((width - ft_strlen(str)), len);
		len += ftp_dot(str, precision);
	}
	else if (who == 3) 			// Avec un nombre
	{
		len = add_spaces((width - ft_strlen(str)), len);
		len += ftp_putstr((uint8_t *)str);
	}
	else
		return (len += ftp_putstr((uint8_t *)str));
	return (len);
}

int					call_putstr(char *str, va_list args, t_docker *data)
{
	char			*argument;

	argument = va_arg(args, char *);
//	ft_putstr("\nwidth\n\n");
//	ft_putnbr(data->width);
//	ft_putstr("\n\n");
//	ft_putstr("\nprecision\n\n");
//	ft_putnbr(data->precision);
//	ft_putstr("\n\n");
	if (data->width >= 1 && data->dot == 0 && data->less == 0) // Avec un 'nombre'
		data->len = ftp_less_test(data->width, data->precision, argument, data->len, 3);
	else if (data->dot == 1 && data->less == 1) 			// '-' et un '.'
		data->len = ftp_less_test(data->width, data->precision, argument, data->len, 1);
	else if (data->less == 1 && str && data->dot == 0)		// Avec un '-'
		data->len = ftp_less_test(data->width, data->precision, argument, data->len, -1);
	else if (data->width >= 1 && data->dot == 1 && data->less == 0)	// Avec un 'nombre' et un '.'
		data->len = ftp_less_test(data->width, data->precision, argument, data->len, 2);
	else if (data->dot == 1 && data->less == 0 && data->width == 0)	// Avec un '.'
		data->len = ftp_less_test(data->width, data->precision, argument, data->len, 0);
	else
		data->len = ftp_less(data->len, argument, 0, 0);
	return (0);
}
