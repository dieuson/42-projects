#include "../includes/lem-in.h"

void 		free_tab(char ****tab)
{
	FT_INIT(int, ligne, 0);
	while (*(tab) && (*tab)[ligne])
	{
		free_simple_tab(&(*tab)[ligne]);
		free((*tab)[ligne]);
		(*tab)[ligne] = NULL;
		ligne++;
	}
	free(*tab);
	*tab = NULL;
}

char 		***malloc_tab(char ***tab)
{
	char 	***fraiche_tab;

	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while (tab && tab[ligne])
		ligne++;
	fraiche_tab = (char ***)malloc(sizeof(char **) * (ligne + 2));
	ligne = 0;
	while (tab && tab[ligne])
	{
		while (tab[ligne] && tab[ligne][colonne])
			colonne++;
		fraiche_tab[ligne] = (char **)malloc(sizeof(char *) * (colonne + 1));
		colonne = 0;
		ligne++;
	}
	return (fraiche_tab);
}

char 		***copy_tab(char ***src, char ***dest)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 0);
	while (src && src[ligne])
	{
		while (src[ligne] && src[ligne][colonne])
		{
			dest[ligne][colonne] = ft_strdup(src[ligne][colonne]);
			colonne++;
		}
		dest[ligne][colonne] = NULL;
		colonne = 0;
		ligne++;
	}
	dest[ligne] = NULL;
	return (dest);
}

char 		***new_tab(char ****tab)
{
	char 	***fraiche_tab;

	if (!tab)
		return (fraiche_tab = (char ***)malloc(sizeof(char **) * 2));
	fraiche_tab = malloc_tab(*tab);
	fraiche_tab = copy_tab(*tab, fraiche_tab);
	free_tab(&(*tab));
	return (fraiche_tab);
}