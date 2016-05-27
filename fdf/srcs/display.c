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
    	mlx_pixel_put(data->mlx, data->win , tmp->x * data->zoom, 
    	tmp->y * data->zoom, tmp->z ?  0x00FF00FF : 0x0000FFFF);
   // 	printf("x =%lf, y =%lf, z =%lf\n", tmp->x, tmp->y, tmp->z);
		tmp = tmp->next;
    }
    if (data)
    	return ;
}