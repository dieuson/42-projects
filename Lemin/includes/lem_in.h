/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:54 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 15:58:35 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c
# include "../srcs/get_next_line/get_next_line.h"

typedef struct				s_ref
{
	char					*name_ref;
	int						nb_ants_ref;
}							t_ref;

typedef struct				s_cells
{
	char					*name;
	char					*someone;
	char					*route;
	int						pos_x;
	int						pos_y;
	struct s_cells			*next;
	char					*neighbor;
}							t_cells;

typedef struct				s_check
{
	int						ants;
	char					*start_cell;
	char					*end_cell;
	int						start;
	int						end;
	int						links;
	int						line_length_min;
	int						nb_args;
	int						*line_length;
	char					***neighbor_tab;
	char					**posibilites;
	t_cells					*start_list;
}							t_check;

void						print_tab(char ***tab);
void						print_simple_tab(char **tab);
int							check_nb_args(char *line);
int							find_way(t_check *check);
int							start_end_min(char *line, t_check *check);
int							build_list(t_cells **cells,
							t_check *check, char *line);
void						free_chaine(t_cells **cells, t_check *check);
void						store_road(t_check *check, char *road);
void						create_neighor_tab(t_check *check);
char						*find_args(char ***tab, char *name, int nb);
char						*one_good_road(t_check *check, int nb_arg);
char						**short_way(char **tab);
void						put_route(t_check *check, char **good_roads);
t_cells						*find_cell(t_check *check, char *cell_name);
char						*ft_strrnchr(char *str, int c, int nb);
int							ft_len_tab(char **tab);
int							verif_double(t_cells **cells, t_check *check);
int							bad_cell(t_check *check, char *road, char *cell);
char						*new_cell(char *road, t_check *check);
int							distrib_moove_ant(t_check *check);
void						free_simple_tab(char ***tab);
char						***new_tab(char ****tab);
void						free_simple_tab(char ***tab);
char						**new_simple_tab(char ***tab);
void						print_route(char **route, char *someone,
							char *name);
t_cells						*find_ant_nb(int nb, t_check *check);
int							calc_last_ligne(t_check *check, t_ref *ref);
char						*named(t_check *check, t_ref *ref);
int							verif_someone_lemin(t_check *check);
char						**store_good_ways(t_check *check);
int							*store_length_line(char **good_roads,
							int *line_length_min);
int							nb_cells(char *road);
char						*first(char *road);
char						*find_neighbor(char *road, char *name,
							t_check *check);
char						**del_over_road(char **tab, t_check *check);
void						free_simple_int_tab(int **tab);
void						free_tab(char ****tab);

#endif
