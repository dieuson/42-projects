/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:48:37 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:56:00 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../srcs/ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <stdio.h>
#include <stdint.h>

typedef struct				s_file
{
	char 					*path;
	char					*name;
	char					*date;
	struct s_file			*next;
	struct s_file			*prev;
	struct s_file 			*directories;
}							t_file;

typedef struct				s_store
{
	char 					*flags;
	char 					*path;
	char 					**args;
	int	 					argc;
	t_file					*start_list;
}							t_store;

int 						detect_flags(char ***argv, int argc,
							t_store *store);
int 						parse_dir(struct dirent* fd, char *file,
							t_file *files, t_store *store);
int							print_help();
int 						error_flags(char c);
int							build_list(t_file **files, struct dirent* fd,
							t_store *store);
void 						print_list(t_store *store);
t_file						*sort_by_name(t_file *head, t_store *store);
int 						perror_ls();

#endif
