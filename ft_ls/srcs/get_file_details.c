/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_details.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:33:47 by dvirgile          #+#    #+#             */
/*   Updated: 2016/05/31 15:38:27 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**get_date(struct stat infos, char *flags)
{
	char		**date_tmp;
	char		**date;
	char		*tmp;
	struct tm	*ref;

	if (flags && flags[5] == 'u')
		tmp = ctime(&infos.st_atime);
	else
		tmp = ctime(&infos.st_mtime);
	date_tmp = ft_strsplit(tmp, ' ');
	if (!date_tmp)
		return (NULL);
	date = (char **)malloc(sizeof(char*) * 5);
	date[0] = ft_strdup(date_tmp[1]);
	date[1] = ft_strdup(date_tmp[2]);
	tmp = ft_strrchr(date_tmp[3], ':');
	ref = gmtime(&infos.st_mtime);
	date[2] = ref->tm_mon > 6 ? ft_strsub(date_tmp[4], 0,
	ft_strlen(date_tmp[4]) - 1) : ft_strsub(date_tmp[3], 0,
	(ft_strlen(date_tmp[3]) - ft_strlen(tmp)));
	date[3] = NULL;
	free_simple_tab(&date_tmp);
	return (date);
}

t_file		*get_owners(struct stat infos, t_file *new)
{
	struct passwd	*owner;
	struct group	*owner_grp;

	owner_grp = getgrgid(infos.st_gid);
	owner = getpwuid(infos.st_uid);
	new->owner = owner ? owner->pw_name : NULL;
	new->owner_grp = owner_grp ? owner_grp->gr_name : NULL;
	return (new);
}

char		get_file_type(struct stat infos)
{
	if (S_ISDIR(infos.st_mode))
		return ('d');
	else if (S_ISFIFO(infos.st_mode))
		return ('p');
	else if (S_ISCHR(infos.st_mode))
		return ('c');
	else if (S_ISBLK(infos.st_mode))
		return ('b');
	else if (S_ISLNK(infos.st_mode))
		return ('l');
	else if (S_ISSOCK(infos.st_mode))
		return ('s');
	else if (S_ISREG(infos.st_mode))
		return ('-');
	else
		return ('-');
}

char		*get_rights(struct stat infos)
{
	char	*rights;

	rights = ft_strnew(11);
	rights[0] = get_file_type(infos);
	rights[1] = infos.st_mode & S_IRUSR ? 'r' : '-';
	rights[2] = infos.st_mode & S_IWUSR ? 'w' : '-';
	rights[3] = infos.st_mode & S_IXUSR ? 'x' : '-';
	rights[4] = infos.st_mode & S_IRGRP ? 'r' : '-';
	rights[5] = infos.st_mode & S_IWGRP ? 'w' : '-';
	rights[6] = infos.st_mode & S_IXGRP ? 'x' : '-';
	rights[7] = infos.st_mode & S_IROTH ? 'r' : '-';
	rights[8] = infos.st_mode & S_IWOTH ? 'w' : '-';
	rights[9] = infos.st_mode & S_IXOTH ? 'x' : '-';
	rights[10] = '\0';
	return (rights);
}

t_file		*get_integers_data(struct stat infos, t_file *new, char *flags)
{
	new->nb_blocks = infos.st_blocks;
	new->time_estamp = flags && ft_strchr(flags, 'u') ?
	infos.st_atimespec.tv_sec : infos.st_mtimespec.tv_sec;
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->display = 0;
	new->directories = ft_strchr(new->rights, 'd') ? 1 : 0;
	return (new);
}
