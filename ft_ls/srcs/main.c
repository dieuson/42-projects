/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:46:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/04/29 16:46:12 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void 		init_struct(t_store *store)
{
	store->start_list = NULL;
	store->flags = "";
}


t_file		*create_cells(struct dirent* fd)
{
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = fd->d_name;
	new->path = NULL;
	new->date = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->directories = NULL;
	return (new);
}

void 		print_list(t_store *store)
{
	t_file *tmp;

	tmp = store->start_list;
	while (tmp)
	{
		ft_printf("tmp->name =%s,\n", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_file		*sort_by_name(t_file *head, t_store *store)
{
	t_file		*ptr;
	t_file		*previous;
	t_file		*temp;

	ptr = head;
	previous = ptr;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, (ptr->next)->name) > 0)
		{
//			ft_printf("ptr->name =%s, next->name =%s,\n", ptr->name, (ptr->next)->name);
			head = (ptr == head) ? ptr->next : head;
			previous->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			previous = ptr;
		}
		else
		{
//			ft_printf("else ptr->name =%s, next->name =%s,\n", ptr->name, (ptr->next)->name);
			previous = ptr;
			ptr = ptr->next;
		}
//		ft_printf("\nliste\n");
//		ft_printf("end liste\n");
	}
//	ft_putstr("\n");
	return (head);
		print_list(store);
}

int			build_list(t_file **files, struct dirent* fd, t_store *store)
{
	if (*files)
	{
		(*files)->next = create_cells(fd);
		(*files)->prev = (*files);
		*files = (*files)->next;
	}
	else if (!(*files))
		MULTI(store->start_list, (*files), create_cells(fd));
	return (1);
}

int parse_dir(struct dirent* fd, char *file, t_file *files, t_store *store)
{
	DIR* rep;

	if (!(rep = opendir(file)))
	{
		perror("");
		return (-1);
	}
	while((fd = readdir(rep)))
	{
		if (!ft_strcmp(fd->d_name, ".") || !ft_strcmp(fd->d_name, ".."))
			continue ;
	//	ft_putendl(fd->d_name);
		build_list(&files, fd, store);
	}
	print_list(store);
	files = sort_by_name(store->start_list, store);
	print_list(store);
	if (closedir(rep) == -1)
	{
		perror("");
		return (-1);
	}
	return (0);
}

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

void 	reject_flags(char ***args)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, ligne2, 1);
	while (args[ligne])
	{
		if (args[ligne][0] == '-')
		{
			while (args[ligne2])
			{
				if (!ft_strchr("lartR", args[ligne][colonne]))
					return (error_flags(args[ligne][colonne]));
				colonne++;
			}
		}
		ligne++;
	}
}

int 	detect_flags(char **args, t_store *store)
{
	FT_INIT(int, ligne, 0);
	FT_INIT(int, colonne, 1);
	while (args[ligne])
	{
		if (args[ligne][0] == '-')
		{
			if (!ft_strcmp(args[ligne], "--help"))
				return (print_help());
			while (args[ligne][colonne])
			{
				if (!ft_strchr("lartR", args[ligne][colonne]))
					return (error_flags(args[ligne][colonne]));
				colonne++;
			}
			colonne = 1;
			store->flags = ft_strjoin(store->flags, args[ligne]);
		}
		ligne++;
	}
	if (ft_strlen(store->flags))
		reject_flags(&args);
	return (1);
}

int main (int argc, char **argv)
{
	t_file *files;
	t_store store;
	struct dirent* fichierLu;

	init_struct(&store);
	if (!detect_flags(argv, &store))
		return (0);
	fichierLu = NULL;
	files = NULL;
	if (argc > 1)
		parse_dir(fichierLu, argv[1], files, &store);
	else
		parse_dir(fichierLu, ".", files, &store);
	if (argc || argv)
		return (1);
	return (0);	
}