/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:33:06 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/10 10:14:32 by dvirgile         ###   ########.fr       */
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

void		draw_line1(t_disp *disp, t_cloud *data)
{
	FT_INIT(int, i, 0);
	FT_INIT(double, e, 2 * disp->dy - disp->dx);
	FT_INIT(double, inc1, 2 * (disp->dy -disp->dx));
	FT_INIT(double, inc2, 2 * disp->dy);
	FT_INIT(double, x, disp->x0);
	FT_INIT(double, y, disp->y0);
	mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
	while (i < disp->dx)
	{
		if (e >= 0)
		{
			y += disp->inc_y;
			e += inc1;
		}
		else
			e += inc2;
		x += disp->inc_x;
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		i++;
	}
}

void		draw_line2(t_disp *disp, t_cloud *data)
{
	FT_INIT(int, i, 0);
	FT_INIT(double, e, 2 * disp->dx - disp->dy);
	FT_INIT(double, inc1, 2 * (disp->dx -disp->dy));
	FT_INIT(double, inc2, 2 * disp->dx);
	FT_INIT(double, x, disp->x0);
	FT_INIT(double, y, disp->y0);
	mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
	while (i < disp->dy)
	{
		if (e >= 0)
		{
			x += disp->inc_x;
			e += inc1;
		}
		else
			e += inc2;
		y += disp->inc_y;
		mlx_pixel_put(data->mlx, data->win , x, y, 0x00FFFFFF);
		i++;
	}
}

void bres (t_disp *disp, t_cloud *data)
{
	disp->dx = fabs(disp->x1 - disp->x0);
	disp->dy = fabs(disp->y1 - disp->y0);
	disp->inc_x = disp->x1 < disp->x0 ? -1 : 1;
	disp->inc_y = disp->y1 < disp->y0 ? -1 : 1;

	if (disp->dx > disp->dy)
		draw_line1(disp, data);
	else
		draw_line2(disp, data);
}

t_disp *create_disp_node(t_node *n_0, t_node *n_1, t_cloud *data)
{
	FT_INIT(t_disp *, new, NULL);
	new = (t_disp*)malloc(sizeof(t_disp));
	new->x0 = n_0->x_2d * data->zoom;
	new->y0 = n_0->y_2d * data->zoom;
	new->x1 = n_1->x_2d * data->zoom;
	new->y1 = n_1->y_2d * data->zoom;
	return (new);
}

void	draw_verticaly(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
	FT_INIT(t_node*, tmp_1 , NULL);
	FT_INIT(t_disp *, disp, NULL);
    while (tmp)
    {
		tmp_1 = tmp->next;
		while (tmp_1 && tmp_1->y != (tmp->y + 1))
			tmp_1 = tmp_1->next;
		while (tmp_1 && tmp_1->y == (tmp->y + 1) && tmp_1->x != tmp->x)
			tmp_1 = tmp_1->next;
/*		if (tmp_1 && (tmp_1->y != (tmp->y + 1) || tmp_1->x != tmp->x))
		{
			while (tmp_1 && tmp->prev && tmp_1->y > (tmp->y + 1))
			{
				ft_putstr("bad y\n");
				printf("tmp_1->x =%f, tmp_1->y =%f,\n", tmp_1->x, tmp_1->y);
				tmp_1 = tmp_1->prev;
			}
			}*/
//			while (tmp_1 && tmp_1->y != (tmp->y + 1))
//				tmp_1 = tmp_1->prev;
//	while (tmp_1 && tmp_1->x != tmp->x && tmp_1->y == (tmp->y + 1))
//			tmp_1 = tmp_1->next;
//		if (tmp_1 && tmp_1->x != tmp->x && tmp_1->y == tmp->y + 1)
//			tmp_1 = tmp_1->prev;
		if (tmp_1 && tmp_1->x == tmp->x)
		{
			disp = create_disp_node(tmp, tmp_1, data);
			bres(disp, data);
			free(&disp);
		}
		tmp = tmp->next;
    }
}

void 	draw_points(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
	FT_INIT(t_node*, next , NULL);
	FT_INIT(t_disp *, disp, NULL);
    while (tmp)
    {
    	next = tmp->next;
    	mlx_pixel_put(data->mlx, data->win , tmp->x_2d * data->zoom,
		tmp->y_2d * data->zoom, 0x00FFFFFF);
		if (next && next->y == tmp->y)
		{
			disp = create_disp_node(tmp, next, data);
			if (next->y == tmp->y)
				bres(disp, data);
			free(disp);
		}
		tmp = tmp->next;
    }
	draw_verticaly(start_list, data);
}
