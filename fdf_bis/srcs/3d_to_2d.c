/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:32:47 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/08 11:56:18 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		opcos(double n)
{
	static double	*list;
	int				i;

	if (!list)
	{
		list = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			list[i] = cosf(i * 2 * M_PI / 360);
	}
	return (list[(int)n % 360]);
}

double		opsin(double n)
{
	static double	*list;
	int				i;

	if (!list)
	{
		list = (double *)malloc(sizeof(double) * 360);
		i = -1;
		while (++i < 360)
			list[i] = sinf(i * 2 * M_PI / 360);
	}
	return (list[(int)n % 360]);
}

double		opmod(double n, double base)
{
	return (n < 0.0 ? fmod(((fmod(n, base)) + base), base) : fmod(n, base));
}


t_node		*get_2d_pos(t_node *new, t_cloud *data)
{
	FT_INIT(double, tmp_z, new->z);
	if (tmp_z)
		tmp_z *= data->depth;
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, new->x - data->campos_x);
	FT_INIT(double, y, new->y - data->campos_y);
	FT_INIT(double, z, tmp_z - data->campos_z);
	x_mod = opcos(data->ang_y) * (opsin(data->ang_z) * y
		+ opcos(data->ang_z) * x) - (opsin(data->ang_y) * z);
	y_mod = opsin(data->ang_x) * (opcos(data->ang_y) * z
		+ (opsin(data->ang_y) * (opsin(data->ang_z) * y
		+ opcos(data->ang_z) * x))) + opcos(data->ang_x)
		* (opcos(data->ang_z) * y - opsin(data->ang_z) * x);
	z_mod = opcos(data->ang_x) * (opcos(data->ang_y) * z
		+ (opsin(data->ang_y) * (opsin(data->ang_z) * y
		+ opcos(data->ang_z) * x))) - opsin(data->ang_x)
		* (opcos(data->ang_z) * y - opsin(data->ang_z) * x);
	new->printable = z_mod > 0 && data->zoom >= 0 ? 1 : 0;
	new->x_2d = ((10 / z_mod) * x_mod)  + data->win_x / 2;
	new->y_2d = ((10 / z_mod) * y_mod)  + data->win_y / 2;
	if (new->y > data->win_y || new->x > data->win_x)
		new->printable = 0;
	printf("mod:\n x_mod =%f, y_mod =%f, z_mod =%f,\nnew->pos:\nx_2d = %f , y_2d = %f ,\n",x_mod, y_mod, z_mod, new->x_2d, new->y_2d);
	return (new);
}

/*
t_node		*get_2d_pos(t_node *new, t_cloud *data)
{
	FT_INIT(double, x, new->x*30 - data->campos_x);
	FT_INIT(double, y, new->y*30 - data->campos_y);
	FT_INIT(double, z, new->z - data->campos_z);
	FT_INIT(double, Cx, opcos(data->ang_x));
	FT_INIT(double, Sx, opsin(data->ang_x));
	FT_INIT(double, Cy, opcos(data->ang_y));
	FT_INIT(double, Sy, opsin(data->ang_y));
	FT_INIT(double, Cz, opcos(data->ang_z));
	FT_INIT(double, Sz, opsin(data->ang_z));
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	x_mod = (Cy * (Sz * y + Cz * x)) - (Sy * z);
	y_mod = (Sx * (Cy * z + Sy * (Sz * y + Cz * x))) + (Cx * (Cz * y - Sz * x));
	z_mod = (Cx * (Cy * z + Sy * (Sz * y + Cz * x))) - (Sx * (Cz * y - Sz * x));

	new->x_2d = ((10 / z_mod) * x_mod) + data->win_x / 2;
	new->y_2d = ((10 / z_mod) * y_mod) + data->win_y / 2;

	printf("mod:\n x_mod =%f, y_mod =%f, z_mod =%f,\nnew->pos:\nx_2d = %f , y_2d = %f ,\n",x_mod, y_mod, z_mod, new->x_2d, new->y_2d);
	return (new);
}*/

t_node		*set_2d_pos(t_node *head, t_cloud *data)
{
	FT_INIT(t_node*, tmp, head);
	while (tmp)
	{
		tmp = get_2d_pos(tmp, data);
		tmp = tmp->next;
	}
	return (head);
}
