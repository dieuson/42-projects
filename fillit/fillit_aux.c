/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:14:48 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/25 08:43:44 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_grid(int taille)
{
	int		i;
	int		verif;
	char	*grid;

	i = 0;
	grid = ft_strnew(taille * taille);
	if (!grid)
		return (NULL);
	while (i < (taille * taille))
	{
		verif = 0;
		while (verif < taille)
		{
			grid[i] = '.';
			verif++;
			i++;
		}
		grid[i] = '\n';
		i++;
	}
	grid[i - 1] = '\0';
	return (grid);
}

void	delete_char(char *grille, char c)
{
	int i;

	i = 0;
	while (grille[i])
	{
		if (grille[i] == c)
			grille[i] = '.';
		i++;
	}
}

int		position_diese(char *tetrimino, t_docker *points)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tetrimino[i])
	{
		if (tetrimino[i] != '.' && tetrimino[i] != '\n')
		{
			points->diese[points->pointeur][j] = i % 5;
			points->diese[points->pointeur][j + 1] = i / 5;
			j = j + 2;
		}
		i++;
	}
	return (1);
}

int		write_grid(int *coordonne, char *grille, t_docker *points)
{
	int		p;
	static int test = 0;

	test++;
	p = 0;
	while (p < 4)
	{
		grille[coordonne[p]] = ('A' + points->pointeur);
		p++;
	}
	return (1);
}
