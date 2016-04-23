#include "../includes/lem-in.h"

void 		print_simple_tab(char **tab)
{
	FT_INIT(int, ligne, 0);
	while (tab[ligne])
	{
		ft_putstr(tab[ligne]);
		ft_putstr("\n");
		ligne++;
	}	
}

void 		print_list(t_check *check)
{
	t_cells *tmp;

	tmp = check->start_list;
	while (tmp)
	{
		printf("tmp->name =%s, tmp->route =%s, tmp->someone =%s\n", tmp->name, tmp->route, tmp->someone);
		tmp = tmp->next;
	}
}

void 		print_tab(char ***tab)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while (tab && tab[ligne])
	{
		while (tab[ligne][colonne])
		{
			ft_putstr(tab[ligne][colonne]);
			colonne++;
		}
		colonne = 0;
		ligne++;
		ft_putstr("\n");
	}
}

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