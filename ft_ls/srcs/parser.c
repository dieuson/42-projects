#include "../includes/ft_ls.h"

int parse_dir(struct dirent* fd, char *file, t_file *files, t_store *store)
{
	DIR* rep;

	if (!(rep = opendir(file)))
		return (perror_ls());
	while((fd = readdir(rep)))
	{
		if (!ft_strcmp(fd->d_name, ".") || !ft_strcmp(fd->d_name, ".."))
			continue ;
	//	ft_putendl(fd->d_name);
		store->path = ft_strdup(file);
		build_list(&files, fd, store);
	}
	print_list(store);
	files = sort_by_name(store->start_list, store);
	print_list(store);
	if (closedir(rep) == -1)
		return (perror_ls());
	return (0);
}