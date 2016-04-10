#include "../includes/lem-in.h"

char		*find_args(const char *s, int c, int nb)
{
	char 	*arg;

	if (!s)
		return (NULL);
	FT_INIT(char **, names, ft_strsplit(s, c));
	if (names[nb])
		arg = names[nb];
	else
		return (NULL);
	return (arg);
}

char 		***add_new_line(char ***tab)
{
	char 	***fraiche_tab;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);

	// Attribution memoir a fraiche_tab
	while (tab && tab[ligne])
		ligne++;
	fraiche_tab = (char ***)malloc(sizeof(char **) * (ligne + 1));
	ligne = 0;
	while (tab && tab[ligne])
	{
		while (tab[ligne] && tab[ligne][colonne])
			colonne++;
		fraiche_tab[ligne] = (char **)malloc(sizeof(char *) * (colonne + 1));
		colonne = 0;
		ligne++;
	}
	ligne = 0;
	// Copie du tableau
	while (tab && tab[ligne])
	{
		while (tab[ligne] && tab[ligne][colonne])
		{
			fraiche_tab[ligne][colonne] = tab[ligne][colonne];
			colonne++;
		}
		colonne = 0;
		ligne++;
	}
	ligne = 0;
	while (tab && tab[ligne])
	{
		while (tab[ligne] && tab[ligne][colonne])
		{
	//		free(tab[ligne][colonne]);
			colonne++;
		}
		ligne++;
		colonne = 0;
	}
	return (fraiche_tab);
}

void 		print_tab(char ***diff_ways)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while(diff_ways && diff_ways[ligne])
	{
		colonne = 0;
		while(diff_ways[ligne] && diff_ways[ligne][colonne])
		{
			ft_putstr(diff_ways[ligne][colonne]);
			colonne++;
		}
		ft_putstr("\n");
		ligne++;
	}
}

int 		find_way(t_cells **cells, t_check *check)
{
	char 	***diff_ways;
	t_cells *tmp;

	FT_INIT(int, ligne, 0);
	diff_ways = NULL;
	if (cells)
		diff_ways = NULL;
	tmp = check->start_list;
	while (tmp)
	{
		printf("name %s\n", tmp->name);
		if (tmp->neighbor)
		{
			if (diff_ways)
				diff_ways = add_new_line(diff_ways);
			else
				diff_ways = (char ***)malloc(sizeof(char **) * (ligne + 1));
			diff_ways[ligne] = ft_strsplit(tmp->neighbor, ' ');
			diff_ways[ligne + 1] = NULL;
			ft_putstr("print_tab\n");
			print_tab(diff_ways);
			ft_putstr("end print_tab\n");
			ligne++;
		}
		tmp = tmp->next;
	}
	return (1);
}