/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:40:17 by dvirgile          #+#    #+#             */
/*   Updated: 2016/06/30 12:03:48 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int shell_cd(char *cmd, char **argv)
{
	if (!cmd || !argv)
		return (0);
	return (1);
}

int shell_ls(char *cmd, char **argv)
{
	if (!cmd || !argv)
		return (0);
	if (!ft_strcmp(argv[1], "ls"))
	{
		argv[1] = NULL;
		cmd = "/bin/ls";
		execve(cmd, argv, NULL);
	}
	return (1);
}

void init_minishell(t_sh_data *data)
{
	data->fct_tab[0] = &shell_cd;
}

char **lsh_read_line(char *line)
{
	char **commands;

	commands = NULL;
	if (!line)
		return (NULL);
	if (ft_strchr(line, ' '))
		commands = ft_strsplit(line, ' ');
	else
	{
		commands = (char**)malloc(sizeof(char*) * 2);
		commands[0] = line;
		commands[1] = NULL;
	}
	return (commands);
}

int lsh_launch(char **args)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	if (!args)
		return (0);
	while (args[i])
	{
		if (args[i] && !ft_strcmp(args[i], "ls"))
		{
			tmp = args[i];
			args[i] = ft_strdup("/bin/ls");
			ft_strdel(&tmp);
		}
		i++;
	}
	execve(args[0], args, NULL);
	return (1);
}

int main()
{
	t_sh_data data;
	char *line;
	char **commands;
	int ret;
	pid_t pid;
	char *current_path;
	char *dir_dest;

	ret = 0;
	commands = NULL;
	line = NULL;
	pid = 0;
	dir_dest = "/srcs";
	current_path = getcwd(NULL, 1024);
	if (!current_path)
		perror("Minishell");
	printf("path =%s,\n", current_path);
	dir_dest = ft_strjoin(current_path, dir_dest);
	chdir(dir_dest);

	current_path = getcwd(NULL, 1024);
	printf("path =%s,\n", current_path);
	init_minishell(&data);
	ft_putstr("$> ");
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret)
		{
			pid = fork();
			if (pid == 0)
			{
				commands = lsh_read_line(line);
				lsh_launch(commands);
				free_simple_tab(&commands);
			}
			ret  = 0;					
			wait(&pid);
			ft_putstr("\n$> ");
		}
	}
	return (0);
}