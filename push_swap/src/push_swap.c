#include "../includes/push_swap.h"

void		ft_print_tab(int **tab)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	while (tab[i] && tab)
	{
		while(tab[i][e])
		{
			ft_putnbr(tab[i][e]);
			tab[i][e + 1] ? ft_putstr(" ") : 0;
			e++;
		}
		e = 0;
		i++;
	}
	ft_putstr("\n");
}

int init_tab(t_docker *data, int len, char **elements)
{
	FT_INIT(int, i, 0);
	data->len_a = len + 1;
	data->len_b = 0;
	data->neighbourg_less = 0;
	data->neighbourg_more = 0;
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

void 		ft_memdel_tab(t_docker *data)
{
	if (data->tab)
	{
		ft_memdel((void*)&data->tab[1]);
		ft_memdel((void*)&data->tab[0]);
	}
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
//	ft_print_tab(data.tab);
	print_result(data.pos_tab);
	distrib(data.tab, &data);
	ft_memdel_tab(&data);
	ft_memdel((void*)&data.pos_tab);
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