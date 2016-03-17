#include "../includes/push_swap.h"
#include <stdio.h>

void		ft_print_tab(int **tab)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	while (tab[i] && tab)
	{
		while(tab[i][e])
		{
			ft_putnbr(tab[i][e]);
			e++;
		}
		e = 0;
		i++;
	}
}

void		print_result(int *result)
{
	FT_INIT(int, i, 0);
	while (result[i])
	{
			ft_putnbr(result[i]);
		i++;
	}
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
int init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, 0);
	data->len_a = len + 1;
	data->len_b = 0;
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len))) || 
	!(data->pos_tab = malloc(sizeof(int) * (len))) ||
	!(data->tab[1] = malloc(sizeof(int) * (len))))
		return (0);
	while (i < len)
	{
		data->pos_tab[i] = ft_atoi(elements[i]);
		data->tab[0][i] = ft_atoi(elements[i]);
		i++;
	}
	data->pos_tab = sort_int_tab(data->pos_tab);
	return (1);
}

static void ft_memdel_tab(t_docker *data)
{
	ft_memdel((void*)&data->tab[1]);
	ft_memdel((void*)&data->tab[0]);
	ft_memdel((void*)&data->pos_tab);
}

int			push_swap(int argc, char **elements)
{
	t_docker data;

	if (!check_push_swap(elements))
		return (-1);
	init_tab(&data, argc, elements);
	if (!check_doublon(*data.tab))
	{
		ft_memdel_tab(&data);
		return (-2);
	}
	ft_print_tab(data.tab);
	ft_putstr("\n");
	print_result(data.pos_tab);
	ft_putstr("\n");
	ft_memdel_tab(&data);
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