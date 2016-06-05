#include "../includes/fdf.h"

int 			parser(int fd, t_cloud *data, t_node *nodes)
{
	FT_INIT(char*, line, NULL);
	FT_INIT(int, verif, 1);
	FT_INIT(double, y, 0);

	nodes = NULL;
	while (verif)
	{
		if (!(verif = get_next_line(fd, &line)))
			break ;
		if (!nodes)
			MULTI(data->start_node, nodes, build_list(line, y, data));
		else
			nodes->next = build_list(line, y, data);
		while (nodes && nodes->next)
			nodes = nodes->next;
		if (line)
			ft_strdel(&line);
		y += 1;
	}
//	ft_putstr("\n\n");
//	ft_putendl("PRINT LIST");
//	print_list(data->start_node);
	return (1);
}