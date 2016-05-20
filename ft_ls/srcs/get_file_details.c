#include "../includes/ft_ls.h"

char 		**get_date(struct stat infos, int type)
{
	char 	**date_tmp;
	char 	**date;
	char 	*tmp;
	struct  tm 	*ref;

//	ft_putendl("GET DATE");

	if (type == 1)
	{
//		ft_putendl("GET DATE 1 ");
		tmp = ctime(&infos.st_mtime);
//		ft_putendl("GET DATE after ");
	}
	else if (type == 2)
	{
//		ft_putendl("GET DATE 2 ");
		tmp = ctime(&infos.st_atime);
	}
//	return (NULL);
	date_tmp = ft_strsplit(tmp, ' ');
	if (!date_tmp)
		return (NULL);
	date = (char **)malloc(sizeof(char*) * 5);
	date[0] = ft_strdup(date_tmp[1]);
	date[1] = ft_strdup(date_tmp[2]);
	tmp = ft_strrchr(date_tmp[3], ':');
	ref = gmtime(&infos.st_mtime);
	date[2] = ref->tm_mon > 6 ? ft_strsub(date_tmp[4], 0, ft_strlen(date_tmp[4]) - 1): 
	ft_strsub(date_tmp[3], 0, (ft_strlen(date_tmp[3]) - ft_strlen(tmp)));
	date[3] = NULL;
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

char 		get_file_type(struct stat infos)
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

char 		*get_rights(struct stat infos)
{
	char 	*rights;

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

unsigned int		get_time_estamp(struct stat infos)
{
	unsigned int time_est;
	
//	time_est = infos.st_mtime;	
	time_est = infos.st_mtimespec.tv_sec; 
	return (time_est);
}