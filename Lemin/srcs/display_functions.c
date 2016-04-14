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