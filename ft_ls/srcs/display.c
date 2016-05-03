#include "../includes/ft_ls.h"

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