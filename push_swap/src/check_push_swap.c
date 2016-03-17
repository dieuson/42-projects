#include "../includes/push_swap.h"

int		check_push_swap(char **elements)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	while (elements[e])
	{
		while (elements[e][i])
		{
			if (!ft_strchr("-+0123456789", elements[e][i]))
				return (0);
				i++;
		}
			e++;
			i = 0;
	}
	return (1);
}

int		check_doublon(int *tab)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	while (tab[i])
	{
		while (tab[e])
		{
			if (tab[i] == tab[e])
				return (0);
			e++;
		}
		i++;
	}
	return (1);
}