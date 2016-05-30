#include "../includes/fdf.h"

t_node *create_cell(int x, int y, int value, t_cloud *data)
{
	FT_INIT(t_node *, new, NULL);
	new = (t_node*)malloc(sizeof(t_node));
	new->x = x*30 + data->win_x / 2;
	new->y = y*30  + data->win_y / 2;
//	new->x = x;
//	new->y = y;
	new->z = value;
//	new->z = 10;
//	new->z = value ? 0x00FF0000 : 0x00FFFFFF;
	new = get_3d_pos(new, data);
	new->next = NULL;
	new->prev = NULL;
	if (data)
		new->next = NULL;
	return (new);
}

t_node *build_list(char *line, int y, t_cloud *data)
{
	FT_INIT(t_node *, start_node, NULL);
	FT_INIT(t_node *, new, NULL);
	FT_INIT(char **, tmp, ft_strsplit(line, ' '));
	FT_INIT(double, x, 0);
	FT_INIT(int, i, 0);
	while (tmp && tmp[i])
	{
		if (!new)
			MULTI(start_node, new, create_cell(x, y, ft_atoi(tmp[i]), data));
		else
		{
			new->next = create_cell(x, y, ft_atoi(tmp[i]), data);
			new->prev = new;
			new = new->next;
		}
		i++;
		x++;
	}
	return (start_node);
}