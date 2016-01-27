/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:53:10 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/27 14:51:07 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

void			ft_detect_flags(char *str, t_docker *data)
{
	if (*str == '#' || *str == '0' || *str == '-' || *str == '+' || *str == ' ')
	{
		if (*str == '#')
			data->dieze = 1;
		if (*str == '0')
			data->zero = 1;
		if (*str == '-')
		{
			data->zero = 0;
			data->less = 1;
		}
		if (*str == '+')
			data->more = 1;
		if (*str == ' ')
			data->space = 1;
		str++;
		ft_detect_flags(str, data);
	}
}

void			ft_detect_length(char *str)
{
	if (*str == 'h')
		modifier.h = 1;
}

int				ft_compare(char *str, va_list pointeur, t_docker *data)
{
	if (str[0] == '%')
		return (ftp_putchar('%'));
	ft_detect_flags(str, data);
	if (str[0] == 's')
		return (ftp_putstr(va_arg(pointeur, char*)));
	if (str[0] == 'd' || str[0] == 'i')
		return (ftp_putnbr(va_arg(pointeur, int)));
	if (str[0] == 'D')
		return (ftp_putnbr((int)va_arg(pointeur, long int)));
	if (str[0] == 'p')
	{
		write(1,"FAILED 0x",9);
		return (ftp_putbase((size_t)va_arg(pointeur, void *),  16, 'a') + 6);
	}
	if (str[0] == 'o')
		return (ftp_putbase(va_arg(pointeur, unsigned int),  8, 'a'));
	if (str[0] == 'u')
		return (ftp_putbase(va_arg(pointeur, unsigned int),  10, 'a'));
	if (str[0] == 'x')
		return (ftp_putbase(va_arg(pointeur, unsigned int),  16, 'a'));
	if (str[0] == 'X')
		return (ftp_putbase(va_arg(pointeur, unsigned int),  16, 'A'));
	if (str[0] == 'c')
		return (ftp_putchar(va_arg(pointeur, int)));
	if (str[0] == 'h' && str[1] == 'h')
		return (ftp_flag_hh(str + 2, data, pointeur));
	return (1);
}

int				ft_printf(const char *str, ...)
{
	va_list		pointeur;
	t_docker	data;
	int			length;
	va_start(pointeur, str);

	data.i = 0;
	length = 0;
	while (str[data.i])
	{
		if (str[data.i] != '%')
		{
			ft_putchar(str[data.i]);
			data.i++;
			length++;
		}
		else
		{
			length += ft_compare((char*)(str + data.i + 1), pointeur, &data);
			data.i += 2;
		}
	}
	va_end(pointeur);
	return (length);
}

int			main(void)
{
	int length_p;
	int length_ft_p;

	//CHAR
	char c;
	char *abc;
	unsigned char e;
	c = 'a';
	abc = "abcde";
	e = '/';
	//INT
	int d;
	long int b;
	unsigned int a;
	d = 1542;
	b = 123456789;
	a = 25;

	length_p = 0;
	length_ft_p = 0;
/*
	ft_printf("TEST %%s %%d %%c %%p\n");
	length_ft_p = ft_printf("FT_PRINTF = Allo %s je suis a %d o%c %i adresse = %p\n", "maman", 1, 'k', d, &abc);
	length_p = printf("___PRINTF = Allo %s je suis a %d o%c %i adresse = %p\n", "maman", 1, 'k', d, &abc);
	ft_printf("longueur FT_PRINTF = %d\n", length_ft_p);
	ft_printf("longueur ___PRINTF = %d\n\n", length_p);

	ft_printf("TEST %%x %%X %%o %%u %%D\n");
	length_ft_p = ft_printf("FT_PRINTF = %%x = %x et %%X = %X %%o = %o %%u = %u %%D = %D\n", 1, 1000, a, a, b);
	length_p = printf("___PRINTF = %%x = %x et %%X = %X %%o = %o %%u = %u %%D = %lD\n", 1, 1000, a, a, b);
	ft_printf("longueur FT_PRINTF = %d\n", length_ft_p);
	ft_printf("longueur ___PRINTF = %d\n\n", length_p);

	ft_printf("TEST %%hhi %%hho %%hhu %%hhx %%hhX\n");
	length_ft_p = ft_printf("FT_PRINTF = %%hhi = %hhd %%hho = %hho %%hhu = %hhu %%hhx = %hhx %%hhX = %hhX\n",c, e, e, e, e);
	length_p = printf("___PRINTF = %%hhi = %hhd %%hho = %#0xhho %%hhu = %hhu %%hhx = %hhx %%hhX = %hhX\n",c, e, e, e, e);
	ft_printf("longueur FT_PRINTF = %d\n", length_ft_p);
	ft_printf("longueur ___PRINTF = %d\n\n", length_p);*/
//	printf("x =%d  \n",d);
	ft_printf("%+++----4i",42);
	return (0);
}
