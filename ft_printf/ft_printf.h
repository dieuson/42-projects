/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:55:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/25 13:43:22 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int			ft_printf_putstr(char const *s);
int			ft_compare(char *str, va_list pointeur);
int			ft_printf_putnbr_base(int n, int base);

#endif
