/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Second_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:09:38 by dvirgile          #+#    #+#             */
/*   Updated: 2016/01/25 09:09:39 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

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

char 				*line_to_return_bis(char *buf, char **line, int end)
{
	char			*backslash;
	static char		*reste = NULL;

//	printf("reste = %s\n", reste);
	if (reste != NULL)
	{
		if ((backslash = ft_strchr(reste, '\n')) == NULL)
		{
			reste = ft_strjoin(reste, buf);
			if (end == 0)
				return (*line = reste);
			return ("again");
		}
		backslash = ft_strjoin(backslash, buf);
		if (!(*line = ft_strnew(ft_strlen(reste) - ft_strlen(backslash))))
		{
			ft_putnbr(ft_strlen(reste) - ft_strlen(backslash));
			ft_putstr("toi");
			return ("error");
		}
//		printf("text = %s\nbackslash = %s\n", text, backslash);
		*line = ft_strsub(reste, 0, (ft_strlen(reste) - ft_strlen(backslash)));
	}
	else
	{
		if ((backslash = ft_strchr(buf, '\n')) == NULL)
		{
			reste = ft_strnew(ft_strlen(buf));
			reste = buf;
			return ("again");
		}
		if (!(*line = ft_strnew(ft_strlen(buf) - ft_strlen(backslash))))
			return ("error");
		*line = ft_strsub(buf, 0, (ft_strlen(buf) - ft_strlen(backslash)));
//		reste = backslash + 1;
	}
	reste = backslash + 1;
	return ("lu");
}

char				*read_all(int const fd, char **line)
{
	char			*buf;
	char			*str;
	char			*tmp;
	char			*ret;
	int				val;

	val = 1;
	buf = ft_strnew(BUFF_SIZE + 1);
	str = ft_strnew(1);
	ret = "again";
	tmp = "\0";

	while (ft_strcmp(ret, "again") == 0 && val > 0)
	{
//		printf("buf = %s\n",buf);
		val = read(fd, buf, BUFF_SIZE);
		ret = line_to_return_bis(buf, line, val);
		buf = ft_strnew(BUFF_SIZE);
	}
//	ret = line_to_return(delete_malus(str, ft_strlen(buf)), line);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	char			*ret;

	ret = ft_strnew(10);
	*line = ft_strnew(1);
	if (fd < 0 || fd == 2 || BUFF_SIZE <= 0)
		return (-1);
	ret = read_all(fd, line);
	if (ft_strcmp(ret, "lu") == 0)
	{
//		ft_putstr("LU");
		return (1);
	}
	if (ft_strcmp(ret, "error") == 0)
		return (-1);
	else
		return (0);
	return (-1);
}
