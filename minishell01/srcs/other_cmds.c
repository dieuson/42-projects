/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:44:25 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/06 17:21:26 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	free_namevalue(char **name, char **value)
{
	free((*name));
	free((*value));
	return (0);
}

int			env_format(char *var)
{
	FT_INIT(int, i, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
	FT_INIT(int, j, ft_strlen(ft_strchr(var, '=')) - 1);
	if (ft_strchr(var, '=') == NULL)
		return (0);
	FT_INIT(char *, name, ft_strnew(i));
	FT_INIT(char *, value, ft_strnew(j));
	name = ft_strncpy(name, var, i);
	ft_strcpy(value, ft_strchr(var, '=') + 1);
	FT_MULTI3(i, j, 0);
	if (ft_strchr(value, '='))
		return (free_namevalue(&name, &value));
	while (name[i])
	{
		if (name[i] < 'A' || name[i] > 'Z')
			if (name[i] != '_')
				return (free_namevalue(&name, &value));
		i++;
	}
	free_namevalue(&name, &value);
	return (1);
}

int			distrib_functions(char **commands, t_sh *data)
{
	if (!ft_strcmp(commands[0], "cd"))
		shell_cd(commands, data);
	else if (!ft_strcmp(commands[0], "env"))
		calls(data, commands);
	else if (!ft_strcmp(commands[0], "setenv"))
		calls(data, commands);
	else if (!ft_strcmp(commands[0], "unsetenv"))
		calls(data, commands);
	else if (!ft_strcmp(commands[0], "echo"))
		calls(data, commands);
	else if (!ft_strcmp(commands[0], "exit"))
		exit(EXIT_SUCCESS);
	return (0);
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

static char	**one_shot(char **args, t_sh *data)
{
	FT_INIT(char*, cmd, NULL);

	cmd = ft_strdup(args[0]);
	if (execve(args[0], args, data->env) == -1)
	{
		ft_strdel(&cmd);
		return (get_bin_directories(data->env));
	}
	ft_strdel(&cmd);
	return (NULL);
}

int			lsh_launch(char **args, t_sh *data, int i)
{
	FT_INIT(char*, cmd, NULL);
	FT_INIT(char*, tmp, NULL);
	if (!args)
		return (0);
	data->bin_directories = one_shot(args, data);
	while (data->bin_directories && data->bin_directories[i])
	{
		if (verif_access_others(data->bin_directories[i]))
		{
			cmd = ft_strjoin(data->bin_directories[i], "/");
			tmp = cmd;
			cmd = ft_strjoin(cmd, args[0]);
			ft_strdel(&tmp);
			if (execve(cmd, args, data->env) != -1)
			{
				ft_strdel(&cmd);
				return (1);
			}
			ft_strdel(&cmd);
		}
		i++;
	}
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(args[0], 2);
	return (0);
}
