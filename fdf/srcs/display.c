/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:33:06 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/07 12:21:38 by dvirgile         ###   ########.fr       */
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

void Bresenham(double x0, double y0, double x1, double y1, t_cloud *data)
{
	int x;
	int y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incrE = 2 * dy ;
	int incrNE = 2 * (dy - dx);
	int e = 2 * dy - dx;
	for(x = x0; x <= x1 ; x++)
	{
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		if(e >= 0)
		{
			y += 1;
			e += incrNE;
		}
		else
			e += incrE;
	}
}

void Bresenham_inv(double x0, double y0, double x1, double y1, t_cloud *data)
{
	int x = x0;
	int y;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incrE = 2 * dy ;
	int incrNE = 2 * (dy - dx);
	int e = 2 * dy - dx;
	for(y = y0; y <= y1 ; y++)
	{
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		if(e >= 0)
		{
			x += 1;
			e += incrNE;
		}
		else
			e += incrE;
	}
}

void BresenhamGeneral(double x0, double y0, double x1, double y1, t_cloud *data)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int IncX, IncY;
	if (dx > 0)
		IncX = 1;
	else{
		IncX = -1;
		dx = -dx;
	}
	if(dy > 0)
		IncY = 1;
	else{
		IncY = -1;
		dy = -dy;
	}
	if(dx > dy)
		Bresenham(x0, y0, x1, y1, data);
	else
		Bresenham_inv(x0, y0, x1, y1, data);
}

void	draw_verticaly(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
	FT_INIT(t_node*, tmp_1 , tmp);
	FT_INIT(t_node*, tmp_2 , tmp);
	FT_INIT(double, x0, 0);
	FT_INIT(double, x1, 0);
	FT_INIT(double, y0, 0);
	FT_INIT(double, y1, 0);
    while (tmp)
    {
		tmp_1 = tmp;
		while (tmp_1 && tmp_1->x_2d != tmp->x_2d)
			tmp_1 = tmp_1->next;
		tmp_2 = tmp_1;
		if (tmp_1)
		{
			x0 = tmp_1->x_2d * data->zoom;
			y0 = tmp_1->y_2d * data->zoom;
		}
		while (tmp_2 && tmp_2->x_2d != tmp_1->x_2d)
			tmp_2 = tmp_2->next;
		if (tmp_2)
		{
			y1 = tmp_2->y_2d * data->zoom;
			x1 = tmp_2->x_2d * data->zoom;
			Bresenham(x0, y0, x1, y1, data);
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
			BresenhamGeneral(x0, y0, x1, y1, data);
//			Bresenham(x0, y0, x1, y1, data);
		}
		tmp = tmp->next;
    }
//	draw_verticaly(start_list, data);
}
