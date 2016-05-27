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



double 	get_dx(t_node *tmp)
{
	double dx;

	FT_INIT(double, x, tmp->x);
	FT_INIT(double, y, tmp->y);
	FT_INIT(double, z, tmp->z);
	dx = cos(y) * ((sin(z) * y + cos(z) * x) 
	- (sin(y) * z));
	return (dx);
}

double 	get_dy(t_node *tmp)
{
	double dy;

	FT_INIT(double, x, tmp->x);
	FT_INIT(double, y, tmp->y);
	FT_INIT(double, z, tmp->z);
	dy = sin(x) * (cos(y) * z + (sin(y) * (sin(z) * y + cos(z) * x)) 
		+ cos(x) * ((cos(z) * y) - (sin(z) * x)));
	return (dy);
}

double 	get_dz(t_node *tmp)
{
	double dz;

	FT_INIT(double, x, tmp->x);
	FT_INIT(double, y, tmp->y);
	FT_INIT(double, z, tmp->z);
	dz = cos(x) * (cos(y) * z + sin(y) * (sin(z) * y + cos(z) * x)) - sin(x) * (cos(z) * y - sin(z) * x);
	return (dz);
}

t_node *get_3d_pos(t_node *new, t_cloud *data)
{
	FT_INIT(double, tmp_z, new->z);
//	if (tmp_z)
//		tmp_z *= all->depth;
	FT_INIT(double, e_x, 1);
	FT_INIT(double, e_y, 1);
	FT_INIT(double, e_z, 1);
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, new->x - e_x);
	FT_INIT(double, y, new->y - e_y);
	FT_INIT(double, z, tmp_z - e_z);
	x_mod = opcos(e_y) * (opsin(e_z) * y
		+ opcos(e_z) * x) - (opsin(e_y) * z);
	y_mod = opsin(e_x) * (opcos(e_y) * z
		+ (opsin(e_y) * (opsin(e_z) * y
		+ opcos(e_z) * x))) + opcos(e_x)
		* (opcos(e_z) * y - opsin(e_z) * x);
	z_mod = opcos(e_x) * (opcos(e_y) * z
		+ (opsin(e_y) * (opsin(e_z) * y
		+ opcos(e_z) * x))) - opsin(e_x)
		* (opcos(e_z) * y - opsin(e_z) * x);
//	point->print = z_mod > 0 && all->zoom >= 0 ? 1 : 0;
	new->x = ((10 / z_mod) * x_mod) * data->zoom + data->win_x / 2;
	new->y = ((10 / z_mod) * y_mod) * data->zoom + data->win_y / 2;
	return (new);
}
/*
t_node *get_3d_pos(t_node *new)
{
//	double tmp_x;
//	double tmp_y;
//	double tmp_z;
	double e_x;
	double e_y;
	double e_z;

	e_x = 100;
	e_y = 100;
	e_z = 500;

//	new->x = (e_z * (new->x - e_x)) / (e_z + new->z);
//	new->y = (e_z * (new->y - e_y)) / (e_z + new->z);

//		a ---> new
// 		c ---> camera

			Yeux.z * (Point.x – Yeux.x)
Resultat.x = ————————————— + Yeux.x
			Yeux.z + Point.z


//	tmp_x = get_dx(new);
//	tmp_y = get_dy(new);
//	tmp_z = get_dz(new);

//new->x = (e_z * (new->x - e_x)) / (e_z + new->z) + e_x;
//new->y = (e_z * (new->y - e_y)) / (e_z + new->z) + e_y;

//	new->x = (e_z / tmp_z) * tmp_x - e_x;
//	new->y = (e_z / tmp_z) * tmp_x - e_y;
//	new->z = get_dz(new);
//	new->x = fabs(new->x - new->y) * (500/2);
//	new->x = fabs(new->x + new->y) * (500/2);;
//	new->x =(new->x - new->z)/sqrt(2);
//    new->y =(new->x + 2 * new->y + new->z)/sqrt(6);
//	new->z = 0;
//screen.x = map.x * TILE_WIDTH_HALF - map.y * TILE_WIDTH_HALF;
//screen.y = map.x * TILE_HEIGHT_HALF + map.y * TILE_HEIGHT_HALF;
	return (new);
}*/