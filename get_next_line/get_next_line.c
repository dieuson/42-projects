/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:28:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/02 09:02:54 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					line_to_return(char **reste, char **line, int end)
{
	char			*backslash;

	backslash = ft_strchr(*reste, '\n');
	if (ft_strcmp(*reste, "") == 0)
	{
		ft_memdel((void**)reste);
		ft_memdel((void**)&*line);
		return (0);
	}
	if (end == 0 && !backslash && (*line = *reste) && !backslash)
	{
		*reste = NULL;
		return (1);
	}
	if (!backslash)
		return (2);
	if (!(*line = ft_strnew(ft_strlen(*reste) - ft_strlen(backslash))))
		return (-1);
	ft_memdel((void**)&*line);
	*line = ft_strsub(*reste, 0, (ft_strlen(*reste) - ft_strlen(backslash)));
	*reste = ft_strsub(backslash, 1, ft_strlen(backslash - 1));
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
	val = read(fd, buf, BUFF_SIZE);
	tmp = reste[fd];
	if (reste[fd])
		reste[fd] = ft_strjoin(reste[fd], buf);
	else
		reste[fd] = ft_strdup(buf);
	ft_memdel((void**)&tmp);
	free(buf);
	ret = line_to_return(&reste[fd], line, val);
	if (ret == -1 || val == -1)
		return (-1);
	if (ret == 2)
		return (read_all(fd, line));
	if (ret == 1 && val >= 0)
		return (1);
	ft_memdel((void**)&reste[fd]);
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	if (fd < 0 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	return (read_all(fd, line));
}
