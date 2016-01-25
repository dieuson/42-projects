/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:46:55 by sgaudin           #+#    #+#             */
/*   Updated: 2015/12/18 17:58:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct	s_docker
{
	int 		diese[26][8];
	int 		pointeur;
	int			taille;
}				t_docker;

int		ft_check_tetriminos_lst(t_list **list);
t_list	*make_lst(char *str, int i);
void	ft_diese_to_char(t_list **list);
char	*ft_modif_str(char *str);
char	*ft_recup_file(char *str);
int		ft_check_file(char *str, int i);
char	*create_grid(int taille);
void	delete_char(char *grille, char c);
int		position_diese(char *tetrimino, t_docker *points);
int		write_grid(int *coordonne, char* grille, t_docker *points);
int		ft_sqrt_fillit(int n);

#endif
