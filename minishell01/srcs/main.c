/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:43:54 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/13 17:10:50 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	verif_implements(char *cmd, t_sh *data)
{
	FT_INIT(char**, functions, data->imp_func);
	FT_INIT(int, i, 0);
	while (functions[i])
	{
		if (ft_strlen(cmd) == 0)
			return (0);
		if (!ft_strcmp(cmd, functions[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	prompt(t_sh *data, int ret, int pid)
{
	FT_INIT(char*, line, NULL);
	FT_INIT(char**, commands, NULL);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret && ft_strlen(line))
		{
			commands = lsh_read_line(line);
			free(line);
			if (verif_implements(commands[0], data))
				distrib_functions(commands, data);
			else
			{
				pid = fork();
				if (pid == 0)
				{
					lsh_launch(commands, data, 0);
					exit(0);
				}
			}
			free_simple_tab(&commands);
		}
		wait(&pid);
		ft_putstr("\n$> ");
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_sh	*data;

	data = (t_sh *)malloc(sizeof(t_sh));
	init_implement_functions(data);
	init_env(&(data->env), envp, NULL);
	data->bin_directories = get_bin_directories(envp);
	ft_putstr("$> ");
	prompt(data, 0, 0);
	if (data->imp_func)
		free_env(data->imp_func);
	if (data->bin_directories)
		free_env(data->bin_directories);
	free(data);
	if (argc || argv)
		return (1);
	return (0);
}
