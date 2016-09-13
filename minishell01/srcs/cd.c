/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:42:34 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/13 16:19:59 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			error_cd(char *domain, char *type, char *file)
{
	ft_putstr_fd(domain, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" :", 2);
	ft_putstr_fd(file, 2);
	return (0);
}

char		*get_line(char *search, char **tab)
{
	FT_INIT(int, i, 0);
	if (!tab || !search)
		return (NULL);
	FT_INIT(int, size, ft_strlen(search));
	while (tab[i])
	{
		if (!ft_strncmp(search, tab[i], size))
			return (ft_strchr(tab[i], '=') + 1);
		i++;
	}
	return (NULL);
}

static int	get_index(char *search, char **tab)
{
	FT_INIT(int, i, 0);
	if (!tab || !search)
		return (-1);
	FT_INIT(int, size, ft_strlen(search));
	while (tab[i])
	{
		if (!ft_strncmp(search, tab[i], size))
			return (i);
		i++;
	}
	return (-1);
}

static char	*set_dir_dest(char **commands, char **env)
{
	FT_INIT(char*, dir_dest, NULL);
	FT_INIT(char*, current_path, NULL);
	FT_INIT(char*, tmp, NULL);
	FT_INIT(int, len_tab, 0);
	while (commands && commands[len_tab])
		len_tab++;
	if (len_tab == 1)
		return (ft_strdup(get_line("HOME", env)));
	else if (!ft_strcmp(commands[1], "-"))
		return (ft_strjoin(get_line("OLDPWD", env), commands[1] + 1));
	else if (commands[1][0] == '~')
		return (ft_strjoin(get_line("HOME", env), commands[1] + 1));
	else if (commands[1][0] == '/')
		return (ft_strdup(commands[1]));
	dir_dest = ft_strjoin("/", commands[1]);
	tmp = dir_dest;
	current_path = getcwd(NULL, 1024);
	dir_dest = ft_strjoin(current_path, dir_dest);
	ft_strdel(&tmp);
	free(current_path);
	return (dir_dest);
}

int			shell_cd(char **commands, t_sh *data)
{
	FT_INIT(char*, dir_dest, NULL);
	FT_INIT(char*, dir, NULL);
	if (!commands && data)
		return (0);
	dir_dest = set_dir_dest(commands, data->env);
	if (!verif_access(dir_dest, commands[1]))
	{
		ft_strdel(&dir_dest);
		return (0);
	}
	dir = getcwd(NULL, 1024);
	if (get_index("OLDPWD", data->env) >= 0)
	{
		free(data->env[get_index("OLDPWD", data->env)]);
		data->env[get_index("OLDPWD", data->env)] = ft_strjoin("OLDPWD=", dir);
	}
	if (get_index("PWD", data->env) >= 0)
	{
		free(data->env[get_index("PWD", data->env)]);
		data->env[get_index("PWD", data->env)] = ft_strjoin("PWD=", dir_dest);
	}
	chdir(dir_dest);
	ft_strdel(&dir_dest);
	free(dir);
	return (1);
}
