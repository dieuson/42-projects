#include "../includes/lem-in.h"

t_cells		*create_first_cell(char *line)
{
	char 	*reste_tmp;
	t_cells *new;

	FT_INIT(long int, nb, 0);
	new = malloc(sizeof(t_cells));
	while (*line == ' ' && *line)
		line++;
	FT_INIT(char *, reste, ft_strchr(line, ' '));
	new->name =  ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	while (*reste == ' ' && *reste)
		reste++;
	reste_tmp = reste;
	reste = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(ft_strchr(reste, ' '))));
	nb = ft_atoi(reste);
	new->pos_x =  nb <= 2147483647 && nb >= 0 ? nb : -1;
	reste_tmp = ft_strsub(reste_tmp, ft_strlen(reste), (ft_strlen(reste_tmp) - ft_strlen(reste)));
	while (*reste_tmp == ' ' && *reste_tmp)
		reste_tmp++;
	nb = ft_atoi(reste_tmp);
	new->pos_y = nb <= 2147483647 && nb >= 0 ? nb : -1;
	free(reste);
	new->next = NULL;
	return (new);
}

int 		link_cells(t_cells **cells, char *line)
{
	char 	*name1;
	char 	*name2;

	FT_INIT(int, check, 0);
	FT_INIT(t_cells*, tmp, *cells);
	FT_INIT(t_cells*, test, *cells);
	FT_INIT(t_cells*, tmp2, *cells);
	while (*line == ' ' && *line)
		line++;
	FT_INIT(char *, reste, ft_strchr(line, '-'));
	name1 = ft_strsub(line, 0, (ft_strlen(line) - ft_strlen(reste)));
	name2 = ft_strsub(reste, 1, (ft_strlen(reste) - 1));
	printf("name1 =%s, name2 =%s\n", name1, name2);
	while (tmp->next && ft_strcmp(tmp->name, name1) != 0)
		tmp = tmp->next;
	if (!ft_strcmp(tmp->name, name1))
		check++;
	while (tmp2->next && ft_strcmp(tmp2->name, name2) != 0)
		tmp2 = tmp2->next;
	if (!ft_strcmp(tmp2->name, name2))
			check++;
	if (check != 2)
		return (0);
	ft_putstr("test\n");
//	if (tmp->neighbor)
		while (tmp->neighbor && tmp->neighbor->next)
		{
			ft_putstr("tmp tour\n");
			tmp->neighbor = tmp->neighbor->next;
		}

	ft_putstr("test2\n");
//	if (tmp2->neighbor)
	while (tmp2->neighbor && tmp2->neighbor->next)
		{
			ft_putstr("tmp2 tour\n");
			tmp2->neighbor = tmp2->neighbor->next;
		}
	//ft_putstr("test2\n");
//	tmp->neighbor =  malloc(sizeof(t_cells));
	test = tmp;
	tmp->neighbor = tmp2;
	tmp->neighbor->next =  NULL;
	ft_putstr("test3\n");
//	tmp->neighbor->next =  malloc(sizeof(t_cells*));
//	tmp2->neighbor =  malloc(sizeof(t_cells));
	tmp2->neighbor = test;
//	tmp2->neighbor->next = NULL;
//	tmp2->neighbor->next = malloc(sizeof(t_cells));
	ft_putstr("test4\n");

//	tmp2->neighbor->next =  malloc(sizeof(t_cells*));
	printf("tmp2->name =%s| neighbor =%s|, pos_x =%d| pos_y =%d|\n", tmp2->name, tmp2->neighbor->name, tmp2->neighbor->pos_x, tmp2->neighbor->pos_y);
	printf("tmp->name =%s| neighbor =%s|, pos_x =%d| pos_y =%d|\n", tmp->name, tmp->neighbor->name, tmp->neighbor->pos_x, tmp->neighbor->pos_y);
	return (1);
}

int			start_end_min(char *line, t_check *check, t_cells *cells)
{
	if (!ft_strcmp("##start", line))
		return (check->start = 1);
	if (!ft_strcmp("##end", line))
		return (check->end = 1);
	if (check->start)
	{
		check->start_cell = line;
		check->start = 0;
		return (build_list(&cells, check, line));
	}
	else if (check->end)
	{
		check->end_cell = line;
		check->end = 0;
		return (build_list(&cells, check, line));
	}
	return (0);
}