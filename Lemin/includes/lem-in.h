
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:13:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/01 12:44:26 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEM_IN_H
# define	LEM_IN_H
# include "../srcs/get_next_line/get_next_line.h"
# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c
#include <stdio.h>

typedef struct				s_check
{
	int						ants;
	char					*start_cell;
	char					*end_cell;
	int						start;
	int						end;
	int						nb_args;
}							t_check;

typedef struct				s_cells
{
	char           			*name;
	int						someone;
	int 					pos_x;
	int 					pos_y;
	struct s_cells 			*next;
	struct s_cells			*neighbor;
}							t_cells;

int					check_lemin(char *line, t_check *check, t_cells *cells);

#endif










