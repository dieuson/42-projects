#include "../includes/push_swap.h"
#include <stdio.h>

int			init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, 0);
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len))) || 
	!(data->tab[1] = malloc(sizeof(int) * (len))))
		return (0);
	while (i < len)
	{
		data->tab[0][i] = ft_atoi(elements[i]);
		i++;
	}
	return (1);
}



int			push_swap(int argc, char **elements)
{
	t_docker data;

	if (!check_push_swap(elements))
		return (-1);
	FT_INIT(int, i, 0);
	init_tab(&data, argc, elements);
	if (!check_doublon(*(data.tab)))
		return (-2);
	while(data.tab[0][i])
	{
//		ft_putnbr(data.tab[0][i]);
		i++;
	}
	if (elements && argc)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	FT_INIT(int, err, 0);
	if (argc > 1)
	{
		err = push_swap((argc - 1), argv + 1);
		if (err == -1)
			ft_putstr("Error char\n");
		if (err == -2)
			ft_putstr("Error doublon\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}