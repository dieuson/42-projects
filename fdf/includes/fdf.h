/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:54 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/24 11:31:51 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c
# include "../srcs/get_next_line/get_next_line.h"
#include "mlx.h"
#include <math.h>

#include <stdio.h>

typedef struct				s_node
{
	double 					x;
	double 					z;
	double 					y;
	struct s_node			*next;
	struct s_node			*prev;
}							t_node;

typedef struct				s_cloud
{
	double 					pos_x;
	double 					pos_y;
	double					zoom;
	int 					win_x;
	int 					win_y;
	void 					*mlx;
    void 					*win;
	t_node 					*start_node;
	t_node	 				*end_node;
}							t_cloud;

int 						distrib_key(int key_value, t_cloud *data);
void					 	draw_points(t_node *start_list, t_cloud *data);
t_node 						*get_3d_pos(t_node *new, t_cloud *data);
int 						parser(int fd, t_cloud *data, t_node *nodes);
t_node 						*build_list(char *line, int y, t_cloud *data);
void 						print_list(t_node *start_list);

#endif
