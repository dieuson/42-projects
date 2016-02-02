/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:38:27 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/02 12:42:34 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/includes/libft.h"
# define BUFF_SIZE 2

typedef struct		s_docker
{
	int pointeur;
}					t_docker;

int					get_next_line(int const fd, char **line);

#endif
