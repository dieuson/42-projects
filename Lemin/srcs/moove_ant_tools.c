#include "../includes/lem-in.h"

char 		*named(t_check *check, t_ref *ref)
{
	char 	*ant_name;

	if (ref->nb_ants_ref > check->ants)
		return (NULL);
	ant_name = ref->name_ref;
	ant_name = ft_strjoin(ant_name, ft_itoa(ref->nb_ants_ref));
	ref->nb_ants_ref++;
	return (ant_name);
}

int 		verif_someone_lemin(t_check *check)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		if (tmp->someone && ft_strcmp(tmp->name, check->end_cell))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int 		send_last_ligne(int *result, t_check *check, t_ref *ref)
{
	FT_INIT(int, nb, 0);
	FT_INIT(int, min, 0);
	FT_INIT(int, line, 0);
	FT_INIT(int, nb_ants, (check->ants - ref->nb_ants_ref) + 1);
	while (result[line])
	{
		if (ft_abs(nb_ants - result[line]) <= ft_abs(nb_ants - min))
		{
			min = result[line];
			nb = line;
		}
		line++;
	}
	return (nb);
}

int 		calc_last_ligne(t_check *check, t_ref *ref)
{
	FT_INIT(int, line, 0);
	FT_INIT(int*, result, NULL);
	FT_INIT(int, addition, 0);
	while (check->line_length[line])
		line++;
	line--;
	result = (int *)malloc(sizeof(int) * line);
	FT_INIT(int, line2, line);
	while (line >= 0 && check->line_length[line])
	{
		while (line2 >= 0 && check->line_length[line2])
		{
			addition += (check->line_length[line] + 1) 
			- check->line_length[line2];
			line2--;
		}
		result[line] = addition;
		line--;
		line2 = line;
		addition = 0;
	}
	return (send_last_ligne(result, check, ref));
}