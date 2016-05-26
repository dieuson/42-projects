#include "../includes/mlx.h"
#include "../includes/fdf.h"
#include <stdio.h>

void 			init_struct(t_cloud *data)
{
	data->start_node = NULL;
	data->end_node = NULL;
	data->pos_y = 0;
	data->pos_x = 0;
}

void 	print_list(t_node *start_list)
{
	FT_INIT(t_node *, tmp, start_list);
	while (tmp)
	{
		if (tmp == start_list)
			printf(" %d ", tmp->value);
		else
			printf("%2d ", tmp->value);
		if ((tmp->next && (tmp->next)->x == 0))
			printf("\n");
		tmp = tmp->next;
	}
}

t_node *create_cell(int x, int y, int value)
{
	FT_INIT(t_node *, new, NULL);
	new = (t_node*)malloc(sizeof(t_node));
	new->x = x * 10;
	new->y = y * 10;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node *build_list(char *line, int y)
{
	FT_INIT(t_node *, start_node, NULL);
	FT_INIT(t_node *, new, NULL);
	FT_INIT(char *, str_val, NULL);
	FT_INIT(char *, tmp, ft_strchr(line, ' '));
	FT_INIT(int, x, 0);
	while (line)
	{
		str_val = tmp ? ft_strsub(line, 0, ft_strlen(line) 
			- ft_strlen(tmp)) : line;
		if (!new)
			MULTI(start_node, new, create_cell(x, y, ft_atoi(str_val)));
		else
		{
			new->next = create_cell(x, y, ft_atoi(str_val));
			new->prev = new;
			new = new->next;
		}
		if (!ft_strcmp(str_val, line))
			break ;
		while (tmp && *tmp && *tmp == ' ')
			(tmp)++;
		ft_strdel(&str_val);
		x++;
		line = tmp;
		tmp	 = ft_strchr(line, ' ');
	}
	return (start_node);
}

int 			parser(int fd, t_cloud *data, t_node *nodes)
{
	FT_INIT(char*, line, NULL);
	FT_INIT(int, verif, 1);
	FT_INIT(int, y, 0);
	nodes = NULL;
	while (verif)
	{
		if (!(verif = get_next_line(fd, &line)))
			break ;
		ft_putendl(line);
		if (!nodes)
			MULTI(data->start_node, nodes, build_list(line, y));
		else
			nodes->next = build_list(line, y);
		while (nodes && nodes->next)
			nodes = nodes->next;
		if (line)
			ft_strdel(&line);
		y++;
	}
	ft_putstr("\n\n");
	ft_putendl("PRINT LIST");
	print_list(data->start_node);
	return (1);
}

int 			main(int argc, char **argv)
{
    void 		*mlx;
    void 		*win;
    int 		fd;
    t_cloud 	data;
    t_node 		nodes;
    FT_INIT(t_node*, tmp , NULL);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "mlx 42");
    init_struct(&data);
    if (!(fd = open(argv[1], O_RDONLY)))
    {
    	ft_putstr("Error Open File\n");
    	return (0);
    }
	if (argc != 2)
    {
    	ft_putstr("Error parameters\n");
    	return (0);
    }
    if (!parser(fd, &data, &nodes))
    	return (0);
    close(fd);
    tmp = data.start_node;
    while (tmp->next)
    {
		mlx_pixel_put(mlx,win, tmp->x, tmp->y, 0x00FFFFFF + tmp->value);
		tmp = tmp->next;
    }
	mlx_loop(mlx);
	//ft_putendl("");
    return (0);
}