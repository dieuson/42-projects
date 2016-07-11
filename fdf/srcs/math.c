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

t_node *get_3d_pos(t_node *new, t_cloud *data)
{
	FT_INIT(double, tmp_z, new->z);
	if (tmp_z)
		tmp_z *= data->depth;
	FT_INIT(double, campos_z, data->e_z);
	FT_INIT(double, campos_x, data->e_x);
	FT_INIT(double, campos_y, data->e_y);
	FT_INIT(double, camang_z, data->ang_z);
	FT_INIT(double, camang_x, data->ang_x);
	FT_INIT(double, camang_y, data->ang_y);
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, new->x*30 - campos_x);
	FT_INIT(double, y, new->y*30 - campos_y);
	FT_INIT(double, z, tmp_z - campos_z);
	FT_INIT(double, Cx, cos(camang_x));
	FT_INIT(double, Sx, sin(camang_x));
	FT_INIT(double, Cy, cos(camang_y));
	FT_INIT(double, Sy, sin(camang_y));
	FT_INIT(double, Cz, cos(camang_z));
	FT_INIT(double, Sz, sin(camang_z));

	x_mod = (Cy * (Sz * y + Cz * x)) - (Sy * z);
	y_mod = (Sx * (Cy * z + Sy * (Sz * y + Cz * x))) + (Cx * (Cz * y - Sz * x));
	z_mod = (Cx * (Cy * z + Sy * (Sz * y + Cz * x))) - (Sx * (Cz * y - Sz * x));

//	new->x_2d = (-10 * x_mod) / z_mod + data->win_x / 2;
//	new->y_2d = (-10 * y_mod) / z_mod - data->win_y / 2;
	new->x_2d = ((-10 / z_mod) * x_mod) + data->win_x / 21;
	new->y_2d = ((-10 / z_mod) * y_mod) - data->win_y / 2;
	printf("x_2d = %f , y_2d = %f ,\n", new->x_2d, new->y_2d);
	return (new);
}

t_node *set_3d_pos(t_node *head, t_cloud *data)
{
	FT_INIT(t_node*, tmp, head);
	while (tmp)
	{
		tmp = get_3d_pos(tmp, data);
		tmp = tmp->next;
	}
	return (head);
}
