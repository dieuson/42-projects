/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:28:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/11 09:50:19 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*line_to_return(char *text, char **line)
{
	char			*backslash;
	static char		*reste = NULL;

	if (reste != NULL)
	{
		if ((backslash = ft_strchr(reste, '\n')) == NULL)
			return (*line = reste);
		if (!(*line = ft_strnew(ft_strlen(reste) - ft_strlen(backslash))))
			return ("error");
		*line = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(backslash)));
	}
	else
	{
		if ((backslash = ft_strchr(text, '\n')) == NULL)
			return (*line = text);
		if (!(*line = ft_strnew(ft_strlen(text) - ft_strlen(backslash))))
			return ("error");
		*line = ft_strsub(text, 0, (ft_strlen(text) - ft_strlen(backslash)));
	}
	if (!(reste = (char *)malloc(sizeof(char) * ft_strlen(backslash) + 1)))
		return ("error");
	reste = backslash + 1;
	return ("lu");
}

char				*copy(char *str, int index, int coef, int length)
{
	char			*s;
	int				i;
	int				e;

	e = 0;
	i = index;
	if (!(s = malloc(sizeof(char*) * (coef * length) + 1)))
		return (NULL);
	while (length > 0)
	{
		s[e] = str[i];
		e++;
		i++;
		length--;
	}
	s[e] = '\0';
	return (s);
}

char				*delete_malus(char *str, int length)
{
	unsigned int	i;
	unsigned int	valider;
	char			*line;
	char			*s1;
	char			*s2;

	i = 0;
	while (str[i])
		i++;
	valider = 0;
	s1 = copy(str, (i - (length * 2)), 2, length);
	s2 = copy(str, (i - length), 1, length);
	while (s1[length] == s2[length] && length > 0)
	{
		valider++;
		length--;
	}
	if (s1[length] != s2[length])
		valider--;
	line = ft_strnew(ft_strlen(str) - valider);
	line = ft_strncpy(line, str, (ft_strlen(str) - valider));
	return (line);
}

char				*read_all(int const fd, char **line)
{
	char			*buf;
	char			*str;
	char			*tmp;
	char			*ret;

	buf = ft_strnew(BUFF_SIZE + 1);
	str = "\0";
	tmp = "\0";
	while (read(fd, buf, BUFF_SIZE))
	{
		str = ft_strnew(ft_strlen(tmp) + ft_strlen(buf) + 1);
		str = ft_strcat(str, tmp);
		str = ft_strcat(str, buf);
		tmp = ft_strnew(ft_strlen(str) + 1);
		tmp = str;
	}
	ret = line_to_return(delete_malus(str, ft_strlen(buf)), line);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	char			*ret;

	if (fd >= 0 && fd != 2 && BUFF_SIZE > 0)
	{
		ret = read_all(fd, line);
		if (ft_strcmp(ret, "lu") == 0)
			return (1);
		if (ft_strcmp(ret, "error") == 0)
			return (-1);
		else
			return (0);
	}
	return (-1);
}
