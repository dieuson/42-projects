#include "../includes/ft_ls.h"

int		print_help()
{
	ft_printf("Usage: ft_ls [OPTION]... [FILE]...\n");
	ft_printf("List information about the FILEs (the current directory by default).\n");
	ft_printf("Mandatory arguments to long options are mandatory for short options too.\n");
	ft_printf("  -a, --all                  do not ignore entries starting with .\n");
	ft_printf("  -l                         use a long listing format\n");
	ft_printf("  -r, --reverse              reverse order while sorting\n");
	ft_printf("  -R, --recursive            list subdirectories recursively\n");
	ft_printf("  -t                         sort by modification time, newest first\n");
	ft_printf("      --help                 display this help and exit\n");	
	return (0);
}


int 	error_flags(char c)
{
	ft_printf("ls: invalid option -- '%c'\nTry './ft_ls --help' for more information.\n", c);
	return (0);
}

int 	perror_ls(char *file)
{
	perror(file);
	return (0);
}