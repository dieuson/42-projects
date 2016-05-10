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
	char 					*absolute_path;
	char					*name;
	char					**date;
	char 					*owner;
	char 					*owner_grp;
	char 					*rights;
	int 					size;
	int 					link;
	int						*time_past;
	struct s_file			*next;
	struct s_file			*prev;
	int						directories;
}							t_file;

typedef struct				s_store
{
	char 					*flags;
	char 					*path;
	char 					**tab;
	int	 					argc;
	int 					len_tab;
	t_file					*start_list;
}							t_store;

char				 		**copy_argv(char **argv);
char				 		**ft_strjoin_tab(char **t1, char **t2);
char				 		**flag_R(t_store *store, int nb_dir);
char			 			**get_date(struct stat infos);
char						*get_owner(struct stat infos);
char						*get_owner_grp(struct stat infos);
char 						*get_rights(struct stat infos);
int							*get_time_pass(struct stat infos);
void		 				free_struct(t_store *store);
void 						free_tab_cell(t_file ***tab);
void 						free_list(t_file *files);
char			 			**verif_double(char **argv, int *argc);
int					 		parse_dir(char *file, t_file **files, t_store *store);
int 						verif_flag_a(t_store *store, char *name);
t_file						*create_cells(struct dirent* fd, t_store *store);
int							ft_strcmp_abs(const char *s1, const char *s2);
void 						print_data(t_store *store);
char 						**parse_args(char **argv, t_file *files, t_store *store);	
void						print_simple_tab(char **tab);
void 						distrib_sort_data(char ***tab, t_store *store);
char 						**new_simple_tab(char ***tab);
char 						**copy_simple_tab(char **src, char **dest);
int 						detect_flags(char ***argv, int argc, t_store *store);
int							print_help();
int 						error_flags(char c);
t_file						*build_list(t_file **files, t_store *store, t_file **tab);
void 						print_list(t_store *store);
int							sort_files(char *file, t_store *store, t_file **files);
int 						perror_ls();

#endif
