/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:06:07 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/28 14:48:11 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			init_struct(t_cloud *data)
{
	data->ang_x = 0;
	data->ang_y = 0;
	data->ang_z = 0;
	data->campos_x = 0;
	data->campos_y = 0;
	data->campos_z = 0;
	data->win_x = 500;
	data->win_y = 500;
	data->zoom = 1;
	data->depth = 0;
	data->start_node = NULL;
	data->end_node = NULL;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "mlx_win");
}
void			error_fdf(char *error_name)
{
	perror(error_name);
	exit(0);
}

int 			distrib_key(int key_value, t_cloud *data)
{
	if (key_value == 65307 || key_value == 53)
		exit(0);
/*	else if (key_value == 69 || key_value == 65451)
		data->zoom += 0.1;
	else if (key_value == 78 || key_value == 65453)
		data->zoom -= 0.1;*/
	else if (key_value == 69 || key_value == 65451)
		data->depth += 0.1;
	else if (key_value == 78 || key_value == 65453)
		data->depth -= 0.1;
	else if (key_value == 125)
		data->ang_y += 15;
	else if (key_value == 126)
		data->ang_y -= 15;
	else if (key_value == 123)
			data->ang_x += 15;
	else if (key_value == 124)
		data->ang_x -= 15;
	else if (key_value == 258)
		data->ang_z += 1;
	else if (key_value == 269)
		data->ang_z -= 1;
	else if (key_value == 116)
		data->ang_x += 1;
	else if (key_value == 121)
		data->ang_x -= 1;
	else if (key_value == 86)
		data->ang_y += 1;
	else if (key_value == 88)
		data->ang_y -= 1;
	printf("key =%d,\n", key_value);
	mlx_clear_window(data->mlx, data->win);
	set_2d_pos(data->start_node, data);
    draw_points(data->start_node, data);
	return (0);
}

int				main(int argc, char **argv)
{
	t_cloud		data;

	init_struct(&data);
	if (argc != 2)
		error_fdf("fdf");
	parser(argv, &data);
	draw_points(data.start_node, &data);
    mlx_hook(data.win, 2, (1L << 0), distrib_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
