/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:53:10 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/25 17:53:43 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int			ftp_putstr(char const *s)
{
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

int			ftp_putnbr(int n)
{
    int len;

    len = 0;
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
        return (11);
    }
    else
    {
        if (n < 0)
        {
            write(1, "-", 1);
            n = -n;
            len++;
        }
        if (n > 9)
            len += ftp_putnbr(n / 10);
        ft_putchar((n % 10) + '0');
        len++;
    }
      return (len);
}

int			ftp_putbase(unsigned int n, unsigned int base, char letter)
{
    int len;

    len = 0;
    if (base > 0 && base <= 10)
    {
        if (n >= base)
            len += ftp_putbase((n / base), base, letter);
        ft_putchar((n % base) + '0');
        len++;
    }
    else if (base == 16)
    {
        if (n >= 16)
        {
            len += ftp_putbase((n / 16), base, letter);
            n %= 16;
        }
        if ((n % 16) >= 10)
            ft_putchar((n % 10) + letter);
        else
            ft_putchar((n % 16) + '0');
        len++;
    }
    return (len);
}

int			ft_compare(char *str, va_list pointeur)
{
    int 	i;

    i  = 0;
    if (str[i] == 's')
        return (ftp_putstr(va_arg(pointeur, char*)));
    if (str[i] == 'd' || str[i] == 'i')
        return (ftp_putnbr(va_arg(pointeur, int)));
    if (str[i] == 'D')
        return (ftp_putnbr((int)va_arg(pointeur, long int)));
    if (str[i] == 'p')
    {
        write(1,"FAILED 0x",9);
        return (ftp_putbase((size_t)va_arg(pointeur, void *),  16, 'a') + 6);
    }
    if (str[i] == 'o')
        return (ftp_putbase(va_arg(pointeur, int),  8, 'a'));
    if (str[i] == 'u')
        return (ftp_putbase(va_arg(pointeur, int),  10, 'a'));
    if (str[i] == 'x')
        return (ftp_putbase(va_arg(pointeur, int),  16, 'a'));
    if (str[i] == 'X')
        return (ftp_putbase(va_arg(pointeur, int),  16, 'A'));
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
            length++;
        }
        else
        {
            length += ft_compare((char*)(str + i + 1), pointeur);
            i += 2;
        }
    }
    va_end(pointeur);
    return (length);
}


int			main(void)
{
//    char *test1 = "al";
    int length_p;
    int length_ft_p;
    char *abc;
    unsigned int a;
    long int b;

    b = 1000000000000;
    abc = "s";
    a = 25;
    length_p = 0;
    length_ft_p = 0;
//    void *adresse = &test1;
//    int test2 = (int)adresse;

    ft_printf("TEST %%s %%d %%c %%p\n");
    length_ft_p = ft_printf("FT_PRINTF = Allo %s je suis a %d o%c %i adresse = %p\n", "maman", -1, 'k', 1000, &abc);
    length_p = printf("___PRINTF = Allo %s je suis a %d o%c %i adresse = %p\n", "maman", -1, 'k', 1000, &abc);
    ft_printf("longueur FT_PRINTF = %d\n", length_ft_p);
    ft_printf("longueur ___PRINTF = %d\n\n", length_p);

    ft_printf("TEST %%x %%X %%o %%u %%D\n");
    length_ft_p = ft_printf("FT_PRINTF = %%x = %x et %%X = %X %%o = %o %%u = %u %%D = %D\n", 1, 1000, a, a, b);
    length_p = printf("___PRINTF = %%x = %x et %%X = %X %%o = %o %%u = %u %%D = %D\n", 1, 1000, a, a, b);
    ft_printf("longueur FT_PRINTF = %d\n", length_ft_p);
    ft_printf("longueur ___PRINTF = %d\n\n", length_p);
    return (0);
}
