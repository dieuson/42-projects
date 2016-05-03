#include "../includes/ft_ls.h"

t_file		*sort_by_name(t_file *head, t_store *store)
{
	t_file		*ptr;
	t_file		*ptr2;
	t_file		*temp;

	FT_INIT(int, verif, 0);
	ptr = head;
	ptr2 = ptr->next;
	while (ptr->next)
	{
		while (ptr2->next)
		{
			if (ft_strcmp(ptr->name, ptr2->name) > 0)
				{
				temp = ptr2->next;
				ptr2->next = ptr;
//				ptr2->prev = ptr->prev;
				ptr->prev = ptr2;
				ptr->next = temp;
//				ptr2->prev = ptr->prev;
//				ptr = temp;
//				ptr->next = temp->next;
				
				verif++;
				break;

			}
			ptr2 = ptr2->next;
		}
		if (!verif)
			ptr = ptr->next;
		else
			ptr = head;
		ptr2 = ptr->next;
		verif = 0;
		print_list(store);
		ft_putstr("\n\n");
	}
	return (head);
}
