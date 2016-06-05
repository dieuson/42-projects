#include "../includes/fdf.h"

t_node *create_cell(double x, double y, double value, t_cloud *data)
{
	FT_INIT(t_node *, new, NULL);
	FT_INIT(double, coef, 30);
	new = (t_node*)malloc(sizeof(t_node));
	new->x = x * coef;
	new->y = y * coef;
//	new->x = x;
//	new->y = y;
	new->z = value;
//	new->z = 10;
	new = get_3d_pos(new, data);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node *build_list(char *line, double y, t_cloud *data)
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