#include "../includes/ft_ls.h"

char 		**get_date(struct stat infos)
{
	char 	**date_tmp;
	char 	**date;
	char 	*tmp;

	date_tmp = ft_strsplit(ctime(&infos.st_mtime), ' ');
	date = (char **)malloc(sizeof(char*) * 4);
	date[0] = ft_strdup(date_tmp[1]);
	date[1] = ft_strdup(date_tmp[2]);
	tmp = ft_strrchr(date_tmp[3], ':');
	date[2] = ft_strsub(date_tmp[3], 0, (ft_strlen(date_tmp[3]) - ft_strlen(tmp)));
	date[3] = NULL;
	free_simple_tab(&date_tmp);
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

t_file		*create_cells(struct dirent* fd, t_store *store)
{
	struct stat infos;

	FT_INIT(char*, path, ft_strjoin(store->path, fd->d_name));
	stat(path, &infos);
//	ft_printf("path =%s, nb_args =%d,\n", path, store->argc)                                                                                                                                 ;
	FT_INIT(t_file *, new, (t_file *)malloc(sizeof(t_file)));
	new->name = ft_strdup(fd->d_name);
	new->path = ft_strdup(store->path);
	new->date = get_date(infos);
	new->owner =  get_owner(infos);
	new->owner_grp = get_owner_grp(infos);
	new->size = infos.st_size;
	new->link = infos.st_nlink;
	new->rights = get_rights(infos);
	new->next = NULL;
	new->prev = NULL;
	new->directories = NULL;
	ft_strdel(&path);
	return (new);
}

int			build_list(t_file **files, struct dirent* fd, t_store *store)
{
	DIR* 	rep;

	FT_INIT(int, ligne, 0);
	while (store->tab[ligne])
	{
		if (!(rep = opendir(store->path)))
			return (perror_ls());
		fd = readdir(rep);
		while(fd && ft_strcmp(fd->d_name, store->tab[ligne]))
			fd = readdir(rep);
		if (*files)
		{
			(*files)->next = create_cells(fd, store);
			(*files)->prev = (*files);
			*files = (*files)->next;
		}
		else if (!(*files))
			MULTI(store->start_list, (*files), create_cells(fd, store));
		if (closedir(rep) == -1)
			return (perror_ls());
		ligne++; 
	}
//	print_list(store);
	return (1);
}