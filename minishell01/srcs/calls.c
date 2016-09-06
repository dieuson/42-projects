/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:42:25 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/05 17:42:26 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		calls(t_sh *data, char **commands)
{
	if (!ft_strcmp("env", commands[0]))
		msh_env(data);
	else if (!ft_strcmp("setenv", commands[0]))
		msh_setenv(data, commands[1]);
	else if (!ft_strcmp("unsetenv", commands[0]))
		msh_unsetenv(data, commands[1]);
	else if (!ft_strcmp("echo", commands[0]))
		msh_echo(data, commands);
	else if (!ft_strcmp("exit", commands[0]))
		exit(EXIT_SUCCESS);
	else
	{
		ft_putendl("Unknown command");
		return (0);
	}
	return (1);
}
