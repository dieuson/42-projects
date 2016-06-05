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

void 	draw_points(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
    while (tmp)
    {
    	mlx_pixel_put(data->mlx, data->win , tmp->x_2d * data->zoom, 
    	tmp->y_2d * data->zoom, 0x00FFFFFF);
		tmp = tmp->next;
    }
    if (data)
    	return ;
}