/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:33:06 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/07 14:00:40 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 	print_list(t_node *start_list)
{
	FT_INIT(t_node *, tmp, start_list);
	while (tmp)
	{
		if (tmp == start_list)
			printf(" %lf ", tmp->z);
		else
			printf("%2lf ", tmp->z);
		if ((tmp->next && (tmp->next)->x == 0))
			printf("\n");
		tmp = tmp->next;
	}
}

void Bresenham(double x0, double y0, double x1, double y1, t_cloud *data, int inc_y)
{
	int x;
	int y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incrE = 2 * dy ;
	int incrNE = 2 * (dy - dx);
	int e = 2 * (dy - dx);
	for(x = x0; x <= x1 ; x++)
	{
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		if(e >= 0)
		{
			y += 1 * inc_y;
			e += incrNE;
		}
		else
			e += incrE;
	}
}

void Bresenham_inv(double x0, double y0, double x1, double y1, t_cloud *data, int inc_x)
{
	int x = x0;
	int y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incrE = 2 * dy ;
	int incrNE = 2 * (dx - dy);
	int e = 2 * (dx - dy);
	while (y <= y1)
	{
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		if(e >= 0)
		{
			x += 1 * inc_x;
			e += incrNE;
		}
		else
			e += incrE;
		y += 1;
	}
}

void BresenhamGeneral(double x0, double y0, double x1, double y1, t_cloud *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int IncX, IncY;
	if (dx > 0)
		IncX = 1;
	else if (dx < 0)
	{
		IncX = -1;
		dx = -dx;
	}
	else
		IncX = 0;
	if(dy > 0)
		IncY = 1;
	else if (dy < 0)
	{
		IncY = -1;
		dy = -dy;
	}
	else
		IncY = 0;
	if (dx > dy)
		Bresenham(x0, y0, x1, y1, data, IncY);
	else
		Bresenham_inv(x0, y0, x1, y1, data, IncX);
}

void	draw_verticaly(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
	FT_INIT(t_node*, tmp_1 , tmp);
	FT_INIT(double, x0, 0);
	FT_INIT(double, x1, 0);
	FT_INIT(double, y0, 0);
	FT_INIT(double, y1, 0);
    while (tmp)
    {
		tmp_1 = tmp->next;
		while (tmp_1 && tmp_1->x != tmp->x && tmp_1->y != tmp->y + 1)
			tmp_1 = tmp_1->next;
		if (tmp_1)
		{
			x0 = tmp->x_2d * data->zoom;
			y0 = tmp->y_2d * data->zoom;
			y1 = tmp_1->y_2d * data->zoom;
			x1 = tmp_1->x_2d * data->zoom;
//			if (x0 == x1)
				BresenhamGeneral(x0, y0, x1, y1, data);
		}
		tmp = tmp->next;
    }
}

void 	draw_points(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
	FT_INIT(t_node*, next , NULL);
	FT_INIT(double, x0, 0);
	FT_INIT(double, x1, 0);
	FT_INIT(double, y0, 0);
	FT_INIT(double, y1, 0);
    while (tmp)
    {
    	next = tmp->next;
		x0 = tmp->x_2d * data->zoom;
		y0 = tmp->y_2d * data->zoom;
    	mlx_pixel_put(data->mlx, data->win , tmp->x_2d * data->zoom, tmp->y_2d * data->zoom, 0x00FFFFFF);
		if (next)
		{
			y1 = next->y_2d * data->zoom;
			x1 = next->x_2d * data->zoom;
//			if (y1 == y0)
				BresenhamGeneral(x0, y0, x1, y1, data);
//			Bresenham(x0, y0, x1, y1, data);
		}
		tmp = tmp->next;
    }
	draw_verticaly(start_list, data);
}
