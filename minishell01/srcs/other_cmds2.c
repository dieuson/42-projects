/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cmds2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:44:04 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/13 16:26:23 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**lsh_read_line(char *line)
{
	FT_INIT(char **, commands, NULL);
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\'') || ft_strchr(line, '\"'))
	{
		if (!(commands = quote(line)))
			commands = ft_strsplit(line, ' ');
	}
	else if (ft_strchr(line, ' ') || ft_strchr(line, '\t'))
		commands = ft_strsplit(line, ' ');
	else
	{
		commands = (char**)malloc(sizeof(char*) * 2);
		commands[0] = ft_strdup(line);
		commands[1] = NULL;
	}
	return (commands);
}

int			verif_access_others(char *path)
{
	struct stat infos;

	lstat(path, &infos);
	if (access(path, F_OK) != 0)
		return (0);
	else if (access(path, X_OK) != 0 || !S_ISDIR(infos.st_mode))
		return (0);
	else if (!S_ISDIR(infos.st_mode))
		return (0);
	return (1);
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
