#include "../includes/ft_ls.h"

int 		*create_int_tab(int len)
{
	int 	*fraiche;

	FT_INIT(int, line, 0);
 	fraiche = (int*)malloc(sizeof(int) * len);
 	while (line < len)
 	{
 		fraiche[line] = 0;
 		line++;
 	}
 	return (fraiche);
}

int 		len_str(char *str)
{
	FT_INIT(int, len, 0);
	while (str && str[len])
		len++;
	return (len);
}

int 		len_nb(int nb)
{
	FT_INIT(int, len, 0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}