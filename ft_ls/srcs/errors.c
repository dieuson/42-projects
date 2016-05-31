/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:26:45 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/31 15:27:03 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_help(void)
{
	ft_putstr("Usage: ft_ls [OPTION]... [FILE]...\n");
	ft_putstr("List information about the FILEs ");
	ft_putstr("(the current directory by default).\n");
	ft_putstr("Mandatory arguments to long options are ");
	ft_putstr("mandatory for short options too.\n");
	ft_putstr("  -a,       do not ignore entries starting with .\n");
	ft_putstr("  -l        use a long listing format\n");
	ft_putstr("  -r, 	   reverse order while sorting\n");
	ft_putstr("  -R,       list subdirectories recursively\n");
	ft_putstr("  -t        sort by modification time, newest first\n");
	ft_putstr("  --help    display this help and exit\n");
	ft_putstr("  -u        with -lt: sort by, and show, access time\n");
	ft_putstr("            with -l: show access time and sort by name\n");
	ft_putstr("            otherwise: sort by access time\n");
	ft_putstr("  -f        do not sort\n");
	ft_putstr("	 -g 	   like -l, but do not list owner\n");
	ft_putstr("  -c 	   show in red repositories, in green link files\n");
	exit(0);
}

int		error_flags(char c)
{
	ft_printf("ls: invalid option -- '%c'\n", c);
	ft_putstr("Try './ft_ls --help' for more information.\n");
	return (0);
}

int		perror_ls(char *file)
{
	perror(file);
	return (0);
}
