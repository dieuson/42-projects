#include "../includes/push_swap.h"

void	tab_copy(int **src, int **dest, int len_a, int len_b)
{
	FT_INIT(int, i, 0);;
	FT_INIT(int, e, 0);
	FT_INIT(int, len, len_a);
	while (i < 2)
	{
		while (e < len)
		{
			dest[i][e] = src[i][e];
			e++;
		}
		len = len_b < 0 ? 0 : len_b;
		e = 0;
		i++;
	}
}