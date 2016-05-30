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

void 	draw_lines(t_node *tmp, t_cloud *data)
{
	if (!tmp || !tmp->next)
		return ;
	FT_INIT(double, AB, (tmp->next)->x - tmp->x);
	FT_INIT(double, AC, (tmp->next)->y - tmp->y);
	FT_INIT(double, BC, 0);
	FT_INIT(double, coeff_dir, 0);
	FT_INIT(double, y, tmp->y);
	FT_INIT(double, x, tmp->x);
	FT_INIT(double, M, (AC / AB));
	FT_INIT(double, p, 0);

	BC = (AB * AB) + (AC * AC);
	BC = sqrt(BC);
	printf("xa =%f, ya =%f, xb =%f, yb =%f, \n", tmp->x, tmp->y, (tmp->next)->x, (tmp->next)->y);
	printf("AB =%f, AC =%f, BC =%f, \n", AB, AC, BC);
	//if ((tmp->y - (tmp->next)->y) > 0)
	//{
		coeff_dir = AC / AB;		
		coeff_dir /= BC;
	//}
	//else
	//	coeff_dir = 0;
	printf("coef =%f\n", coeff_dir); 
	p =  y - (M * x);
	printf("y =%f, x =%f, x->next =%f, p =%f, \n", y, x, (tmp->next)->x, p);
	while (x < (tmp->next)->x)
	{
		y = M * (tmp->next)->x + p;
		mlx_pixel_put(data->mlx, data->win , x * data->zoom, 
    	y * data->zoom,  0x00FF0000);
//   	printf("x =%f, x->next =%f, y =%f, coeff_dir =%f, \n", x, (tmp->next)->x, y, coeff_dir);
		x ++;
	//	y += incr;
	}
	if (data)
		return ;
}

void 	draw_points(t_node *start_list, t_cloud *data)
{
	FT_INIT(t_node*, tmp , start_list);
    while (tmp)
    {
    	mlx_pixel_put(data->mlx, data->win , tmp->x * data->zoom, 
    	tmp->y * data->zoom, 0x00FFFFFF);
	//	usleep(5000);
  	 	if (tmp->next)
  		  	draw_lines(tmp, data);
//	  	 	printf("x =%lf, x->next =%f, y =%lf, z =%lf\n", tmp->x, (tmp->next)->x ,tmp->y, tmp->z);
		tmp = tmp->next;
    }
    if (data)
    	return ;
}