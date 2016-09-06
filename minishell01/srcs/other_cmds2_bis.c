/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cmds2_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:52:14 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/06 18:17:15 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**spacial_split(char *line)
{
	FT_INIT(char **, commands, NULL);
	FT_INIT(char *, tmp, NULL);
	FT_INIT(char *, to_split, NULL);
	FT_INIT(int, simple_cote, ft_strlen(ft_strchr(line, '\'')));
	FT_INIT(int, double_cote, ft_strlen(ft_strchr(line, '\"')));
	FT_INIT(char, to_search, simple_cote < double_cote && simple_cote  ? '\'' : '\"');
	FT_INIT(size_t, i, 0);

	if (simple_cote < double_cote && simple_cote)
		to_split = ft_strsub(line, 0, ft_strlen(line) - simple_cote);
	else if (double_cote < simple_cote && double_cote)
		to_split = ft_strsub(line, 0, ft_strlen(line) - double_cote);
	commands = ft_strsplit(to_split, ' ');
	tmp = simple_cote < double_cote && simple_cote ? line + simple_cote : line + double_cote;
	ft_putstr(tmp);
	i = ft_strlen(tmp) + 1;
	while (line[i] && line[i] != to_search)
	{
		ft_putchar(line[i]);
		i++;
	}
	exit(0);
	return (commands);
}

char		**lsh_read_line(char *line)
{
	char **commands;

	commands = NULL;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\'') || ft_strchr(line, '\"'))
		commands = spacial_split(line);
	else if (ft_strchr(line, ' '))
		commands = ft_strsplit(line, ' ');
	else
	{
		commands = (char**)malloc(sizeof(char*) * 2);
		commands[0] = ft_strdup(line);
		commands[1] = NULL;
	}
	return (commands);
}

int			verif_access(char *path, char *file)
{
	struct stat infos;

	lstat(path, &infos);
	if (access(path, F_OK) != 0)
		return (error_cd("cd", "no such file or directory", file));
	else if (access(path, X_OK) != 0 || !S_ISDIR(infos.st_mode))
		return (error_cd("cd", "permission denied", file));
	else if (!S_ISDIR(infos.st_mode))
		return (error_cd("cd", "not a directory", file));
	return (1);
}
