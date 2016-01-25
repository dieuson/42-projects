/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readandmodif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:47:59 by sgaudin           #+#    #+#             */
/*   Updated: 2016/01/22 15:18:50 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*iter_char(char *content, char c)
{
	int		i;
	char	*buf;

	i = 0;
	buf = content;
	while (buf[i])
	{
		if (buf[i] == '#')
			buf[i] = c;
		i++;
	}
	return (buf);
}

void		ft_diese_to_char(t_list **list)
{
	t_list	*tmp;
	char	c;

	c = 'A';
	tmp = *list;
	if (ft_strlen((char*)tmp->content) < 20)
		tmp = tmp->next;
	while (tmp->next != NULL)
	{
		tmp->content = iter_char(tmp->content, c);
		c++;
		tmp = tmp->next;
	}
	tmp->content = iter_char(tmp->content, c);
}

char		*ft_recup_file(char *str)
{
	int		fd;
	int		ret;
	char	buf[50];
	char	*result;
	int		size;

	size = 0;
	ret = 0;
	result = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	result = (char*)malloc(sizeof(str) * 10000);
	while ((ret = read(fd, buf, 50)))
	{
		size += ret;
		result = ft_strncat(result, buf, ret);
	}
	return (result);
}

int			ft_check_file(char *str, int i)
{
	int		nb_blocs;
	int		nb_points;
	int		nb_retourligne;

	if (ft_strlen(str) < 16)
		return (1);
	while (str[i])
	{
		nb_blocs = 0;
		nb_points = 0;
		nb_retourligne = 0;
		while (nb_retourligne < 4 && str[i] != '\0')
		{
			if (str[i] == '\n')
				nb_retourligne++;
			else if (str[i] == '.')
				nb_points++;
			else if (str[i] == '#')
				nb_blocs++;
			i++;
		}
		if (nb_points != 12 || nb_blocs != 4)
			return (1);
		i++;
	}
	return (0);
}

int			ft_sqrt_fillit(int n)
{
	int i;

	i = n;
	while (n < i * i)
		i--;
	return (i);
}
