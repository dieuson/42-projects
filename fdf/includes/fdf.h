/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:54 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/24 11:31:51 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define FT_INIT(type,name,value)type name = value
# define TER(si,alors,sinon)si ? alors : sinon
# define MULTI(val_a, val_b, val_c)val_a = val_b = val_c
# include "../srcs/get_next_line/get_next_line.h"

typedef struct				s_node
{
	int 					x;
	int 					value;
	int 					y;
	struct s_node			*next;
	struct s_node			*prev;
}							t_node;

typedef struct				s_cloud
{
	int 					pos_x;
	int 					pos_y;
	t_node 					*start_node;
	t_node	 				*end_node;
}							t_cloud;

#endif
