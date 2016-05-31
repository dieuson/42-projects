/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:28:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 11:55:10 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					line_to_return(char **reste, char **line, int end)
{
	char			*backslash;

	if (ft_strchr(*reste, '\n'))
		backslash = ft_strdup(ft_strchr(*reste, '\n'));
	else
		backslash = NULL;
	if (ft_strlen(*reste) <= 0 && !backslash && end == 0)
		return (0);
	if (!backslash && end == 0 && ft_strlen(*reste) > 0)
	{
		*line = *reste;
		*reste = NULL;
		return (1);
	}
	if (!backslash && end > 0)
		return (2);
	if (!(*line = ft_strnew(ft_strlen(*reste) - ft_strlen(backslash))))
		return (-1);
	ft_memdel((void**)&*line);
	*line = ft_strsub(*reste, 0, (ft_strlen(*reste) - ft_strlen(backslash)));
	ft_memdel((void**)&(*reste));
	*reste = ft_strdup(backslash + 1);
	ft_memdel((void**)&backslash);
	return (1);
}

int					read_all(int const fd, char **line)
{
	char			*buf;
	int				ret;
	int				val;
	static char		*reste[256] = {NULL};
	char			*tmp;

	buf = ft_strnew(BUFF_SIZE + 1);
	if ((val = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	tmp = reste[(fd % 256)];
	if (reste[(fd % 256)])
		reste[(fd % 256)] = ft_strjoin(reste[(fd % 256)], buf);
	else if (!reste[fd % 256])
		reste[(fd % 256)] = ft_strdup(buf);
	free(&buf);
	ft_memdel((void**)&tmp);
	ret = line_to_return(&reste[(fd % 256)], line, val);
	if (ret == -1 || val == -1)
		return (-1);
	if (ret == 2)
		return (read_all(fd, line));
	if (ret == 1 && val >= 0)
		return (1);
	ft_memdel((void**)&reste[fd % 256]);
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	if (fd < 0 || fd == 2 || BUFF_SIZE <= 0 || fd == 1)
		return (-1);
	return (read_all(fd, line));
}
