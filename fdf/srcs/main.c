#include "../includes/fdf.h"

void 			init_struct(t_cloud *data)
{
	data->start_node = NULL;
	data->end_node = NULL;
	data->ang_y = 0;
	data->ang_x = 0;
	data->ang_z = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->e_z = -10;
	data->zoom = -0.5;
    data->mlx = mlx_init();
    data->win_x = 500;
    data->win_y = 500;
    data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "mlx 42");
}

int 			error(char *name)
{
	ft_putendl(name);
	ft_putendl("");
	ft_putendl("--HELP 	FDF");
	ft_putendl("Usage: ./fdf [file] [options]");
	return (0);
}

int 			distrib_key(int key_value, t_cloud *data)
{
	if (key_value == 65307 || key_value == 53)
		exit(0);
	else if (key_value == 69 || key_value == 65451)
		data->zoom += 0.1;
	else if (key_value == 78 || key_value == 65453)
		data->zoom -= 0.1;
	else if (key_value == 125)
		data->e_y += 15;
	else if (key_value == 126)
		data->e_y -= 15;
	else if (key_value == 123)
			data->e_x += 15;
	else if (key_value == 124)
		data->e_x -= 15;
	else if (key_value == 258)
		data->e_z += 1;
	else if (key_value == 269)
		data->e_z -= 1;
	else if (key_value == 116)
		data->ang_x += 1;
	else if (key_value == 121)
		data->ang_x -= 1;
	printf("key =%d,\n", key_value);
	mlx_clear_window(data->mlx, data->win);
	set_3d_pos(data->start_node, data);
    draw_points(data->start_node, data);
	return (0);
}

int 			main(int argc, char **argv)
{
    int 		fd;
    t_cloud 	data;
    t_node 		nodes;


    init_struct(&data);
    if (argc <= 1 || argc >= 3)
    	return (argc <= 1 ? error("Too few arguments") 
    		: error("Too many arguments"));
	if (argc != 2)
    	return (error("Error parameters"));
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    	return (error("Error open file"));
    if (!parser(fd, &data, &nodes))
    	return (error("Parsing Error"));
    close(fd);
    draw_points(data.start_node, &data);
    mlx_key_hook(data.win, distrib_key, &data);
	mlx_loop(data.mlx);
    return (0);
}