/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_recursive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:03:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/22 15:16:13 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			agencement(int *tab, char *grille, t_docker *points, size_t i)
{
	int			coordonne[4];
	int			e;
	int			p;

	while (grille[i])
	{
		e = 0;
		p = 0;
		if (grille[i] == '.')
		{
			while (e < 8 && p >= 0 && p <= 4)
			{
				coordonne[p] = ((tab[e + 1] - tab[1]) * (points->taille + 1)
								+ tab[e] + i - tab[0]);
				e += 2;
				p++;
			}
			if (grille[coordonne[0]] == '.' && grille[coordonne[1]] == '.'
				&& grille[coordonne[2]] == '.' && grille[coordonne[3]] == '.')
				return (write_grid(coordonne, grille, points));
		}
		i++;
	}
	return (0);
}

int			decalle(char *grille, t_docker *points, int nb_pieces)
{
	int	i;

	i = 0;
	if (points->pointeur == nb_pieces + 1)
		return (1);
	while (i >= 0)
	{
		if (agencement(points->diese[points->pointeur], grille, points, i))
		{
			points->pointeur++;
			if (decalle(grille, points, nb_pieces))
				return (1);
			i++;
		}
		else
			i++;
		if (i >= (points->taille * (points->taille + 1)))
			i = -50;
	}
	if (points->pointeur >= 1)
	{
		points->pointeur--;
		delete_char(grille, 'A' + points->pointeur);
	}
	return (0);
}

int			backtrack(t_docker *points, int nb_pieces)
{
	char	*grille;

	points->taille = ft_sqrt_fillit((nb_pieces * 4));
	grille = create_grid(points->taille);
	while (1)
	{
		if (decalle(grille, points, nb_pieces) == 0)
		{
			points->pointeur = 0;
			points->taille++;
			grille = create_grid(points->taille);
			decalle(grille, points, nb_pieces);
		}
		else
		{
			ft_putstr(grille);
			ft_putchar('\n');
			return (1);
		}
	}
	return (0);
}

int			send_list(t_list **list, t_docker *points)
{
	t_list		*tmp;
	int			nb_pieces;

	points->pointeur = 0;
	tmp = *list;
	if (ft_strlen((char*)tmp->content) < 20)
		tmp = tmp->next;
	while (tmp->next != NULL)
	{
		position_diese((char*)tmp->content, points);
		points->pointeur++;
		tmp = tmp->next;
	}
	position_diese((char*)tmp->content, points);
	nb_pieces = points->pointeur;
	points->pointeur = 0;
	backtrack(points, nb_pieces);
	return (1);
}

int			main(int ac, char **av)
{
	char		*str;
	t_list		*list;
	t_docker	*points;

	if (ac == 2)
	{
		str = ft_recup_file(av[1]);
		list = make_lst(str, 0);
		points = malloc(sizeof(t_docker));
		if (ft_check_file(str, 0) == 1 || ft_check_tetriminos_lst(&list) == 1)
		{
			ft_putstr("error\n");
			return (1);
		}
		else
			send_list(&list, points);
	}
	else
		ft_putstr("error\n");
	return (0);
}
