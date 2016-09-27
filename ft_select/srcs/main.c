/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:11:31 by dvirgile          #+#    #+#             */
/*   Updated: 2016/09/27 15:15:57 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void prompt(char **argv, char **envp)
{


}

int main(int argc, char **argv)
{
	FT_INIT(int, nb_loop, 0);
	int i;
	char *name;
	int is_term;


	struct termios *termios_p;

	i = ttyslot();


	printf("fd shell =%d,\n", i);
	is_term = isatty(i);
	printf("is_term? =%d,\n", is_term);
	name = ttyname(i);
	printf("term_name =%s,\n", name);



	while (argv[nb_loop])
		nb_loop++;
	return (0);
}
