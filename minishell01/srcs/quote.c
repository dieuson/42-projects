/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 16:13:31 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/13 16:14:19 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define SIMPLEQ '\''
#define DOUBLEQ '\"'

static int	detect_end_quote(char *line, char quote)
{
	FT_INIT(int, i, 0);
	FT_INIT(int, j, 0);
	while (line[i])
	{
		j = i + 1;
		if (line[i] == quote)
		{
			while (line[j] && line[j] != quote)
				j++;
			if (line[j] != quote)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}

static int	count_quote(char *s, int *i, int *count)
{
	FT_INIT(char, quote, s[(*i)]);
	if (!detect_end_quote(s, quote))
		return (0);
	else
	{
		(*count)++;
		(*i) += 2;
		while (s[(*i)] && s[(*i) - 1] != quote)
			(*i)++;
	}
	return (1);
}

static int	count(char *s)
{
	FT_INIT(int, count, 0);
	FT_INIT(int, i, 0);
	if (s[i] != ' ' && s[i] != '\t' && s[i] != SIMPLEQ && s[i] != DOUBLEQ)
		count++;
	else if (s[i] == SIMPLEQ || s[i] == DOUBLEQ)
		if (!count_quote(s, &i, &count))
			return (-1);
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == SIMPLEQ || s[i] == DOUBLEQ)
		{
			if (!count_quote(s, &i, &count))
				return (-1);
		}
		else if ((s[i - 1] == ' ' || s[i - 1] == '\t')
				 && s[i] != ' ' && s[i] != '\t')
			count++;
		i++;
	}
	return (count);
}

static int	length(char **line, char quote)
{
	FT_INIT(int, i, 1);
	if (quote != -1)
	{
		while ((*line)[i] && (*line)[i] != quote)
			i++;
	}
	else
	{
		while ((*line)[i] && (*line)[i] != ' ' && (*line)[i] != '\t')
			i++;
	}
	if (!i)
		i++;
	return (i);
}

char		**quote(char *line)
{
	FT_INIT(char **, tab, (char **)malloc(sizeof(char *) * count(line) + 1));
	FT_INIT(int, i, 0);
	if (!line || !tab)
		return (NULL);
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
			line++;
		else if (*line == SIMPLEQ || *line == DOUBLEQ)
		{
			if (!(tab[i] = ft_strsub(line, 1, length(&line, *line) - 1)))
				return (NULL);
			line = line + length(&line, *line) + 1;
			i++;
		}
		else
		{
			if (!(tab[i] = ft_strsub(line, 0, length(&line, -1))))
				return (NULL);
			line = line + length(&line, -1);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
