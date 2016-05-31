#include "../includes/fdf.h"

void 			init_struct(t_cloud *data)
{
	data->start_node = NULL;
	data->end_node = NULL;
	data->pos_y = 0;
	data->pos_x = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->e_z = 0;
	data->zoom = 1;
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
/*
void 			apply_fctn(t_cloud *data, , t_node (*f)(t_node* , t_cloud*))
{
	FT_INIT(t_node*, start_list, data->start_node);
	while (start_list->next)
	{
		start_list = f(start_list, start_list->x, start_list->y, start_list->z); 	
		start_list = start_list->next;
	}

}*/


int 			distrib_key(int key_value, t_cloud *data)
{
	if (key_value == 65307)
		exit(0);
	else if (key_value == 65451 || key_value == 65453)
	{
		data->zoom += key_value == 65451 ? 0.1 : -0.1;
		mlx_clear_window(data->mlx, data->win);
	    draw_points(data->start_node, data);
	}
	else if (key_value == 65362)
	{
		data->e_x += 0.1;
		mlx_clear_window(data->mlx, data->win);
	    draw_points(data->start_node, data);
	}
	else if (key_value == 65364)
	{
		data->e_x -= 0.1;
		mlx_clear_window(data->mlx, data->win);
	    draw_points(data->start_node, data);
	}

//	printf("key =%d,\n", key_value);
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