
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:13:05 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/11 11:06:00 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEM_IN_H
# define	LEM_IN_H
# include "../srcs/get_next_line/get_next_line.h"
# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c
#include <stdio.h>

typedef struct				s_ref
{
	char 					*name_ref;
	int 					nb_ants_ref;
}							t_ref;

typedef struct				s_cells
{
	char           			*name;
	char 					*someone;
	char 					*route;
	int 					pos_x;
	int 					pos_y;
	struct s_cells 			*next;
	char					*neighbor;
}							t_cells;

typedef struct				s_check
{
	int						ants;
	char					*start_cell;
	char					*end_cell;
	int						start;
	int						end;
	int						nb_args;
	char 					***neighbor_tab;
	char 					**posibilites;
	t_cells 				*start_list;
}							t_check;

char 						**short_way(char **tab);
char 					 	**store_good_ways(char **tab, t_check *check);
int 						nb_cells(char *road);
char 						**del_over_road(char **tab);
char 						*one_good_road(t_check *check, int nb_arg);
char 						*new_cell(char *road, t_check *check);
void 						print_simple_tab(char **tab);
int 						distrib_moove_ant(t_check *check);
char 						**new_simple_tab(char **tab);
char 						*find_neighbor(char *road, char *name, t_check *check);
char						*find_args(char ***tab, char *name, int nb);
int 						find_way(t_check *check);
void						create_neighor_tab(t_check *check);
char						 ***new_tab(char ***tab);
char						***copy_tab(char ***src, char ***dest);
void						print_tab(char ***tab);
int							check_lemin(char *line, t_check *check, t_cells **cells);
int							build_list(t_cells **cells, t_check *check, char *line);
int							check_nb_args(char *line);
int 						verif_double(t_cells **cells, t_check *check);
int 						link_cells(t_cells **cells, t_cells **start_list, char *line);
t_cells						*create_cells(char *line);
int							start_end_min(char *line, t_check *check);
int							nb_ants(char *line, t_check *check, long int laps);

#endif