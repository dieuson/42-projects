/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 17:25:22 by sgaudin           #+#    #+#             */
/*   Updated: 2016/09/13 17:13:44 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# include "../srcs/get_next_line/get_next_line.h"

typedef struct			s_sh
{
	char				**env;
	char				**imp_func;
	char				**bin_directories;
}						t_sh;

void					error_launch(char *com);

int						shell_cd(char **commands, t_sh *data);
int						error_cd(char *domain, char *type, char *file);
int						verif_access(char *path, char *file);
int						verif_access_others(char *path);
int						distrib_functions(char **commands, t_sh *data);

char					**get_bin_directories(char **envp);
int						shell_cmds(char *cmd, char **argv);
char					**lsh_read_line(char *line);
int						lsh_launch(char **args, t_sh *data, int i);
void					init_implement_functions(t_sh *data);
int						init_env(char ***new_env, char **envp, char *var);
void					free_env(char **env);
int						calls(t_sh *data, char **commands);

int						msh_env(t_sh *data);
int						msh_setenv(t_sh *data, char *new_var);
int						msh_unsetenv(t_sh *data, char *to_del);
int						check_varname(char *var, char *to_check);
int						env_format(char *var);

int						msh_echo(t_sh *data, char **commands);
char					**quote(char *line);
char					*get_line(char *search, char **tab);

#endif
