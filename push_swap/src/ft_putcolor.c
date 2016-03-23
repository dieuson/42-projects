/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:15:33 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/23 14:17:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static char	*ft_putlight(char *color)
{
	if (!ft_strcmp(color, "LIGHT GRAY") || !ft_strcmp(color, "light gray"))
		color = "37";
	if (!ft_strcmp(color, "LIGHT RED") || !ft_strcmp(color, "light red"))
		color = "91";
	if (!ft_strcmp(color, "LIGHT GREEN") || !ft_strcmp(color, "light green"))
		color = "92";
	if (!ft_strcmp(color, "LIGHT YELLOW") || !ft_strcmp(color, "light yellow"))
		color = "93";
	if (!ft_strcmp(color, "LIGHT BLUE") || !ft_strcmp(color, "light blue"))
		color = "94";
	if (!ft_strcmp(color, "LIGHT MAGENTA")
			|| !ft_strcmp(color, "light magenta"))
		color = "95";
	if (!ft_strcmp(color, "LIGHT CYAN") || !ft_strcmp(color, "light cyan"))
		color = "96";
	if (!ft_strcmp(color, "WHITE") || !ft_strcmp(color, "white"))
		color = "97";
	return (color);
	}*/

void		ft_putcolor(t_docker *data, int ligne, int colonne)
{
	FT_INIT(char *, color, "97");
	FT_INIT(int, finish, 0);
	if (data->empty == 3)
	{
		ft_putstr("\033[");
		if (verif_tab(data->tab[0], data, data->len_a - 1))
			color = "92";
		else
			color = "31"; //ROUGE
		finish = 1;
	}
	else if (data->empty == 4)
	{
		if ((data->enum_moove == sa && !ligne &&(colonne == data->len_a - 2 || colonne == data->len_a - 1))||
			(data->enum_moove == sb && ligne &&(colonne == data->len_b - 2 || colonne == data->len_b - 1)))
		{
			ft_putstr("\033[");
			if (data->tab[ligne][colonne] == data->pos_tab[colonne])
				color = "92";
			else
				color = "31"; //ROUGE
			finish = 1;
		}
	}
/*	if (!ft_strcmp(color, "GREEN") || !ft_strcmp(color, "green"))
		color = "32";
	if (!ft_strcmp(color, "YELLOW") || !ft_strcmp(color, "yellow"))
		color = "33";
	if (!ft_strcmp(color, "BLUE") || !ft_strcmp(color, "blue"))
		color = "34";
	if (!ft_strcmp(color, "MAGENTA") || !ft_strcmp(color, "magenta"))
		color = "35";
	if (!ft_strcmp(color, "CYAN") || !ft_strcmp(color, "cyan"))
		color = "36";
	if (!ft_strcmp(color, "DARK GRAY") || !ft_strcmp(color, "dark gray"))
		color = "90";
	if (!ft_strcmp(color, "DEFAULT") || !ft_strcmp(color, "default"))
		color = "39";
	else
	color = ft_putlight(color);*/
	if (finish)
	{
		ft_putstr(color);
		ft_putchar('m');
	}
}
