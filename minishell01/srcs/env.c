/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:43:26 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/06 14:04:33 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_varname(char *var, char *check)
{
	FT_INIT(int, i, ft_strlen(var) - ft_strlen(ft_strchr(var, '=')));
	FT_INIT(int, j, 1);
	if (ft_strchr(check, '=') != NULL)
		j = ft_strlen(check) - ft_strlen(ft_strchr(check, '='));
	FT_INIT(char *, var_name, ft_strnew(i));
	FT_INIT(char *, check_name, ft_strnew(j));
	var_name = ft_strncpy(var_name, var, i);
	check_name = ft_strncpy(check_name, check, j);
	if (!ft_strcmp(var_name, check) || !ft_strcmp(check_name, var_name))
	{
		free(var_name);
		free(check_name);
		return (1);
	}
	else
	{
		free(var_name);
		free(check_name);
		return (0);
	}
}

static int	setenv_check(t_sh *data, char *new_var)
{
	FT_INIT(int, i, 0);
	while (data->env[i])
	{
		if (check_varname(data->env[i], new_var))
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(new_var);
			return (1);
		}
		i++;
	}
	return (0);
}

int			msh_env(t_sh *data)
{
	int		i;

	i = 0;
	if (!data->env)
		return (1);
	while (data->env[i])
	{
		ft_putendl(data->env[i]);
		i++;
	}
	return (0);
}

int			msh_setenv(t_sh *data, char *new_var)
{
	FT_INIT(int, i, 0);
	FT_INIT(char **, tmp, NULL);
	if (!env_format(new_var))
	{
		ft_putstr_fd("Wrong env variable format.\nShould be the"
		" following format : NAME=value. '_' character is allowed in"
		" the name of the variable, and '=' character is forbidden in"
		" the value.", 2);
		return (1);
	}
	if (setenv_check(data, new_var))
		return (0);
	init_env(&tmp, data->env, new_var);
	while (tmp[i])
		i++;
	free_env(data->env);
	data->env = NULL;
	init_env(&(data->env), tmp, NULL);
	i = 0;
	while (data->env[i])
		i++;
	free_env(tmp);
	return (0);
}

int			msh_unsetenv(t_sh *data, char *to_del)
{
	FT_INIT(char **, tmp, NULL);
	FT_INIT(int, i, 0);
	FT_INIT(int, j, 0);
	while (data->env[i])
	{
		j += (check_varname(data->env[i], to_del)) ? 1 : 0;
		i++;
	}
	if (!j || !(tmp = (char **)malloc(sizeof(char *) * i)))
		return (0);
	FT_MULTI3(i, j, 0);
	while (data->env[i])
	{
		if (data->env[i] && !(check_varname(data->env[i], to_del)))
		{
			tmp[j] = ft_strdup(data->env[i]);
			j++;
		}
		i++;
	}
	tmp[j] = NULL;
	free_env(data->env);
	init_env(&(data->env), tmp, NULL);
	free_env(tmp);
	return (0);
}
