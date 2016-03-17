#include "../includes/push_swap.h"
#include <stdio.h>

int	resize_tab(t_docker *data, int len_a, int len_b)
{
	FT_INIT(int, i, 0);
	FT_INIT(int**, tmp, data->tab);
	ft_memdel_tab(data);
	if (!(data->tab = malloc(sizeof(int*) * 2)) ||
	!(data->tab[0] = malloc(sizeof(int) * (len_a))) || 
	!(data->tab[1] = malloc(sizeof(int) * (len_b))))
		return (0);
	while (i < len_a)
	{
		data->tab[0][i] = tmp[0][i];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		data->tab[1][i] = tmp[1][i];
		i++;
	}
	if (data->enum_moove == pb)
			data->tab[1][len_b] = tmp[0][len_a + 1];
	else if (data->enum_moove == pa)
		data->tab[1][len_a] = tmp[0][len_b + 1];
	ft_memdel((void*)&tmp[0]);
	ft_memdel((void*)&tmp[1]);
	return (1);
}

int		m_sa(t_docker *data)
{
	FT_INIT(int, tmp, 0);
	tmp = data->tab[0][data->len_a];
	data->tab[0][data->len_a] = data->tab[0][data->len_a - 1];
	data->tab[0][data->len_a - 1] = tmp;
	return (1);
}

int		m_sb(t_docker *data)
{
	FT_INIT(int, tmp, 0);
	tmp = data->tab[1][data->len_b];
	data->tab[1][data->len_b] = data->tab[1][data->len_b - 1];
	data->tab[1][data->len_b - 1] = tmp;
	return (1);
}

int		m_ss(t_docker *data)
{
	m_sa(data);
	m_sb(data);
	return (1);
}

int		m_pb(t_docker *data)
{
	data->enum_moove = pb;
	resize_tab(data, data->len_a - 1, data->len_b + 1);
	return (1);
}

int		m_pa(t_docker *data)
{
	data->enum_moove = pb;
	resize_tab(data, data->len_a + 1, data->len_b - 1);
	return (1);
}

void 	len_tab(t_docker *data)
{
	FT_INIT(int, i, 0);
	while (data->tab[0][i])
		i++;
	data->len_a = i - 1;
	i = 0;
	while (data->tab[1][i])
		i++;
	data->len_b = i - 1;
}

int 	distrib(int **tab, t_docker *data)
{
	if (!tab)
		return (0);
	len_tab(data);
	ft_print_tab(data->tab);
	m_pb(data);
	ft_print_tab(data->tab);
	return (1);
}