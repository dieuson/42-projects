/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:53:10 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/25 13:54:25 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int			ft_printf_putstr(char const *s)
{
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

int			ft_printf_putnbr_base(int n, int base)
{
    static int length = 0;

    if (n == -2147483648)
        ft_putstr("-2147483648");
    else
    {
        if (n < 0)
        {
            write(1, "-", 1);
            //   length++;
            n = -n;
        }
        if (n >= base)
            ft_putnbr(n / base);
        length++;
        ft_putchar((n % base) + '0');
    }
    printf("\n\nlength = %d\n\n", length);
    return (length);
}

int			ft_compare(char *str, va_list pointeur)
{
    int 	i;

    i  = 0;
    if (str[i] == 's')
        return (ft_printf_putstr(va_arg(pointeur, char*)));
    if (str[i] == 'd' || str[i] == 'i')
        return (ft_printf_putnbr_base(va_arg(pointeur, int),  10));
    if (str[i] == 'c')
        ft_putchar(va_arg(pointeur, int));
    if (str[i] == '%')
        ft_putchar('%');
    return (1);
}

int			ft_printf(const char *str, ...)
{
    va_list pointeur;
    va_start(pointeur, str);
    int i;
    int length;

    i = 0;
    length = 0;
    while (str[i])
    {
        if (str[i] != '%')
        {
            ft_putchar(str[i]);
            i++;
        }
        else
        {
            length = length + i + ft_compare((char*)(str + i + 1), pointeur);
            i = i + 2;
        }
    }
    ft_putstr("\n");
    ft_putnbr(length);
    ft_putstr("\n");
    va_end(pointeur);
    return (length);
}


int			main(void)
{
    char *test1 = "al";
    void *adresse = &test1;
//    int test2 = (int)adresse;

    ft_printf("FT_PRINTF = Allo %s je suis a %d o%c %i\n", "maman", 1, 'k', 20);
    printf("___PRINTF = Allo %s je suis a %d o%c %p", "maman", 10, 'k', adresse);
    return (0);
}
