#include "../includes/push_swap.h"

void		print_result(int *result)
{
	FT_INIT(int, i, 0);
	ft_putstr("RESULT\n");
	while (result[i])
	{
			ft_putnbr(result[i]);
			result[i + 1] ? ft_putstr(" ") : 0;
		i++;
	}
	ft_putstr("\n\n");
}

int 	*sort_int_tab(int *tab)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 1);
	FT_INIT(int, min, 0);
	while (tab[i])
	{
		while (tab[i] < tab[e] && tab[e])
			e++;
		if (tab[i] > tab[e] && tab[e])
		{
			min = tab[i];
			tab[i] = tab[e];
			tab[e] = min;
			i = 0;
		}
		else
			i++;
		e = 0;
	}
	return (tab);
}