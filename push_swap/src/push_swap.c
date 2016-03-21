/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:12:04 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/21 13:25:59 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../test/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			get_next_line(int const fd, char **line);

int			push_swap(int argc, char **elements)
{
	t_docker data;

	static int failed = 0;
	static int ok = 0;
	FT_INIT(int, i, 0);

	if (!check_push_swap(elements))
		return (-1);
	init_tab(&data, argc, elements);
	if (!check_doublon(*data.tab, data.len_a))
	{
		ft_memdel((void*)&data.pos_tab);
		ft_memdel_tab(&data);
		return (-2);
	}
	if (argc == 1)
	{
		ft_print_tab(data.tab, &data);
		return(1);
	}
	i = 0;
//	print_result(data.pos_tab, data.len_a);
	ft_putstr("------------------------------------------------------------------------\n");
	distrib(data.tab, &data);
	if (verif_tab(data.tab[0], &data, 0) == 1)
	{
		ft_putcolor("\nOK\n", "GREEN");
		ft_putcolor("INPUT ", "GREEN");
		while (i < data.len_final)
		{
			ft_putchar(elements[i][0]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		ft_print_tab(data.tab, &data);
		ok++;
	}
	else
	{
		ft_putcolor("\nFAILED\n", "RED");
		ft_putcolor("INPUT ", "RED");
		while (i < data.len_final)
		{
			ft_putchar(elements[i][0]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		print_result(data.pos_tab, data.len_final);
		ft_putcolor("TON ERREUR\n", "RED");
		ft_print_tab(data.tab, &data);
		printf("last_a = %d attendu = %d, last_b = %d, len_a = %d, len_b = %d\n"
			   , data.last_a, data.pos_tab[data.len_a - 1], data.last_b, data.len_a, data.len_b);
		failed++;
	}
	printf("NB_FAILED = %d, NB_OK = %d\n", failed, ok);
	ft_memdel_tab(&data);
	ft_memdel((void*)&data.pos_tab);
	return (0);
}

int main(int argc, char **argv)
{
	FT_INIT(int, err, 0);
	FT_INIT(int, i, 0);
	FT_INIT(int, e, 0);
	int fd;
	char *elements;
	char **str;

	str = NULL;
	if (argc > 1)
	{
		err = push_swap((argc - 1), argv + 1);
		if (err == -1)
			ft_putstr("Error char\n");
		if (err == -2)
			ft_putstr("Error doublon\n");
	}
	else
	{
		str = malloc(sizeof(char *) * 7);
		while (i < 6)
		{
			str[i] = malloc(sizeof(char));
			i++;
		}
		i = 0;
		fd = open("./test/test2", O_RDONLY);
		while (get_next_line(fd, &elements))
		{
			while (i < 6 && e < 5)
			{
				if (ft_strchr("-+0123456789", elements[i]))
				{
					str[e][0] = elements[i];
					//				str[e][1] = '\0';
					e++;
				}
				i++;
			}
			str[e][0] = '\0';
			e = 0;
			i = 0;
			err = push_swap(5, str);
			if (err != 0)
			{
				ft_putstr("Error\n");
				return (-1);
			}
		}
		free(elements);
		while (i < 6)
		{
			free(str[i]);
			i++;
		}
	}
	return (0);
}
