#include "../includes/ft_ls.h"

char 		**get_date(struct stat infos)
{
	char 	**date_tmp;
	char 	**date;
	char 	*tmp;
	struct  tm 	*ref;

	tmp = ctime(&infos.st_mtime);
	date_tmp = ft_strsplit(tmp, ' ');
//	ft_strdel(&tmp);
	date = (char **)malloc(sizeof(char*) * 5);
	date[0] = ft_strdup(date_tmp[1]);
	date[1] = ft_strdup(date_tmp[2]);
	tmp = ft_strrchr(date_tmp[3], ':');
	ref = gmtime(&infos.st_mtime);
	date[2] = ref->tm_mon > 6 ? ft_strsub(date_tmp[4], 0, ft_strlen(date_tmp[4]) - 1): 
	ft_strsub(date_tmp[3], 0, (ft_strlen(date_tmp[3]) - ft_strlen(tmp)));
	date[3] = NULL;
//	free_simple_tab(&date_tmp);
//	free(date_tmp);
	return (date);
}

char		*get_owner(struct stat infos)
{
	struct passwd	*owner;

	if (!(owner = getpwuid(infos.st_uid)))
		return (NULL);
	return (owner->pw_name);
}

char		*get_owner_grp(struct stat infos)
{
	struct group	*owner;

	if (!(owner = getgrgid(infos.st_gid)))
		return (NULL);
	return (owner->gr_name);
}

char 		*get_rights(struct stat infos)
{
	char 	*rights;

	rights = ft_strnew(11);
	rights[0] = S_ISDIR(infos.st_mode) ? 'd' : '-';
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

int					*get_time_estamp(struct stat infos)
{
	struct tm 		*tmp;
	int 			*tab;

	tmp = gmtime(&infos.st_ctime);
//	tmp = gmtime(&infos.st_mtimespec.tv_sec);
//	ft_putstr("test60\n");
	tab = (int*)malloc(sizeof(int) * 7);
//	ft_putstr("test61\n");
	tab[0] = tmp->tm_year;
	tab[1] = tmp->tm_mon;
	tab[2] = tmp->tm_mday;
//	ft_putstr("test64\n");
	tab[3] = tmp->tm_hour;
	tab[4] = tmp->tm_min;
	tab[5] = tmp->tm_sec;
	tab[6] = -255;
//	ft_putstr("test70\n");
	return (tab);
}