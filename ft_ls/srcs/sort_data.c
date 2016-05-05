#include "../includes/ft_ls.h"

int						ft_strcmp_abs(const char *s1, const char *s2)
{
	int					i;
	int 				e;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	e = 0;
	while (str1[i] && str2[e])
	{
		if (str1[i] == '.')
			i++;
		if (str2[e] == '.')
			e++;
		if (ft_tolower(str1[i]) != ft_tolower(str2[e]))
			return (ft_tolower(str1[i]) - ft_tolower(str2[e]));
		i++;
		e++;
	}
	return (ft_strlen(s1) - ft_strlen(s2));
}

void 		sort_tab(char 	***tab)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	FT_INIT(char *, tmp, NULL);
	while ((*tab)[ligne])
	{
		while ((*tab)[ligne2])
		{
			if (ft_strcmp_abs((*tab)[ligne], (*tab)[ligne2]) > 0)
			{
				tmp = (*tab)[ligne2];
				(*tab)[ligne2] = (*tab)[ligne];
				(*tab)[ligne] = tmp;
				ligne = 0;
				ligne2 = ligne + 1;
			}
			else
				ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
}

void 		sort_tab_rev(char 	***tab)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	FT_INIT(char *, tmp, NULL);
	while ((*tab)[ligne])
	{
		while ((*tab)[ligne2])
		{
			if (ft_strcmp_abs((*tab)[ligne], (*tab)[ligne2]) < 0)
			{
				tmp = (*tab)[ligne2];
				(*tab)[ligne2] = (*tab)[ligne];
				(*tab)[ligne] = tmp;
				ligne = 0;
				ligne2 = ligne + 1;
			}
			else
				ligne2++;
		}
		ligne++;
		ligne2 = ligne + 1;
	}
}

void 		distrib_sort_data(char ***tab, t_store *store)
{
	if (store->flags)
	{
		if (ft_strstr(store->flags, "r"))
			sort_tab_rev(tab);
	}
	sort_tab(tab);
}