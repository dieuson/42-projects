/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:09:29 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/28 14:42:08 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H
# include "../srcs/get_next_line/get_next_line.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c

typedef	struct			s_node
{
	double				x;
	double				z;
	double				y;
	double				x_2d;
	double				y_2d;
	int 				printable;
	struct s_node		*next;
	struct s_node		*prev;
}				t_node;

typedef struct			s_disp
{
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	double				inc_x;
	double				inc_y;
	double				dx;
	double				dy;
}						t_disp;

typedef struct			s_cloud
{
	double				ang_x;
	double				ang_y;
	double				ang_z;
	double 				depth;
	double				campos_x;
	double				campos_y;
	double				campos_z;
	double				win_x;
	double				win_y;
	void				*mlx;
	void				*win;
	double				zoom;
	t_node				*start_node;
	t_node				*end_node;
}						t_cloud;

void					draw_points(t_node *start_list, t_cloud *data);
t_node					*get_2d_pos(t_node *new, t_cloud *data);
t_node					*set_2d_pos(t_node *head, t_cloud *data);
t_node					*create_cell(double x, double y, double z, t_cloud *data);
t_node					*build_list(double pos_y, t_cloud *data, char *line);
void					error_fdf(char *error_name);
int 					parser(char **argv, t_cloud *data);
int						get_next_line(int const fd, char **line);

#endif










