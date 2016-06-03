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
# include <stdint.h>

typedef struct				s_file
{
	char					*path;
	char					*absolute_path;
	char					*name;
	char					**date;
	char					*owner;
	char					*owner_grp;
	char					*rights;
	char					*private;
	unsigned int			time_estamp;
	unsigned int			time_lacc;
	unsigned int			time_chan;
	int						*display;
	int						size;
	int						link;
	int						directories;
	int						nb_blocks;
	struct s_file			*next;
}							t_file;

typedef struct				s_args
{
	char					*name;
	struct s_args			*next;
}							t_args;

typedef struct				s_store
{
	char					*flags;
	char					*path;
	int						*len_print;
	int						nb_blocks;
	int						argc;
	int						len_tab;
	t_file					*add_args;
	t_file					*start_list;
}							t_store;

char						get_file_type(struct stat infos);
int							build_list(char *file, char *rights,
							t_store *store, t_file **list);
t_file						*build_args_list(char **argv, t_store *store);
int							*compare_len(char *flags, t_file *files, int *tab);
t_file						*create_simple_cells(char *name, t_store *store);
t_file						*create_cells(char *name, t_store *store,
							int type);
int							*create_int_tab(int len);
char						**copy_simple_tab(char **src, char **dest);
int							detect_flags(char ***argv, int argc,
							t_store *store);
void						distrib_sort_data(char ***tab, t_store *store);
int							error_flags(char c);
void						ft_lstadd_end_ls(t_file **alst, t_file *new);
void						free_struct(t_store *store);
void						free_tab_cell(t_file **tab);
void						free_list(t_file *files);
void						free_int_tab(int **tab, int nb_lines);
int							ft_strcmp_abs(const char *s1, const char *s2);
char						**ft_strdup_tab(char **argv);
char						**ft_strjoin_tab(char **t1, char **t2);
t_file						*cat_args_list(t_file *args, t_store *store);
t_file						*flag_r(t_file *files, int nb_dir, t_store *store);
char						**get_date(struct stat infos, char *flags);
t_file						*get_owners(struct stat infos, t_file *new);
char						*get_rights(struct stat infos);
t_file						*get_integers_data(struct stat infos,
							t_file *new, char *flags);
int							len_str(char *str);
int							len_nb(int nb);
char						**new_simple_tab(char ***tab);
void						print_simple_tab(char **tab);
int							print_help(void);
int							parse_dir(char *file, t_file **files,
							t_store *store);
void						print_data(t_store *store);
int							perror_ls(char *file);
void						print_list(t_file *file);
int							parse_args(char **argv, t_file *files,
							t_store *store);
t_file						*read_elements(t_store *store, int *nb_dir,
							DIR *rep);
int							*reset_int_tab(int *tab, int len);
t_file						*sort_list(t_file *files, t_store *store);
char						**verif_double(char **argv, int *argc);
int							verif_flag_a(t_store *store, char *name);

#endif
