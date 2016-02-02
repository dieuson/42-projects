/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:29:44 by dvirgile          #+#    #+#             */
/*   Updated: 2016/02/02 13:23:27 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	char*line;
	int state;
	int temp;

	state = 1;
	temp = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while (state == 1)
	{
		state = get_next_line(fd, &line);
		printf("state : %d\n", state);
		printf("line : %s\n", line);
		temp = state;// La boucle s'execute en fonction du retour de gnl.
		//state--;// la boucle force 13 tours.
	}
	close(fd);
	return (0);
}
