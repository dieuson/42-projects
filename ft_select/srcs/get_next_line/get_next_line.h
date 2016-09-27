/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:22:16 by sgaudin           #+#    #+#             */
/*   Updated: 2016/09/27 15:14:35 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../libft/includes/libft.h"
# define BUFF_SIZE 80

int		get_next_line(int const fd, char **line);

#endif
