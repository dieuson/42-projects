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
	FT_INIT(double, campos_z, -10);
	FT_INIT(double, campos_x, 0);
	FT_INIT(double, campos_y, 0);
	FT_INIT(double, camang_z, 0);
	FT_INIT(double, camang_x, 0);
	FT_INIT(double, camang_y, 0);
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, new->x - campos_x);
	FT_INIT(double, y, new->y - campos_y);
	FT_INIT(double, z, new->z - campos_z);
	FT_INIT(double, Cx, opcos(camang_x));
	FT_INIT(double, Sx, opsin(camang_x));
	FT_INIT(double, Cy, opcos(camang_y));
	FT_INIT(double, Sy, opsin(camang_y));
	FT_INIT(double, Cz, opcos(camang_z));
	FT_INIT(double, Sz, opsin(camang_z));

	x_mod = (Cy * (Sz * y + Cz * x)) - (Sy * z);
	y_mod = (Sx * (Cy * z + Sy * (Sz * y + Cz * x))) + (Cx * (Cz * y - Sz * x));
	z_mod = (Cx * (Cy * z + Sy * (Sz * y + Cz * x))) - (Sx * (Cz * y - Sz * x));
	printf("x_mod =%f, y_mod =%f, z_mod =%f,\n", x_mod, y_mod, z_mod);
	printf("x =%f, y =%f, z =%f,\n", new->x, new->y, new->z);
//	if (data)
//		new->x_2d = (-10 * x_mod) / z_mod;
	new->x_2d = (-10 * x_mod) / z_mod - data->win_x / 2;
	new->y_2d = (-10 * y_mod) / z_mod - data->win_y / 2;
	return (new);
}	