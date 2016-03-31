#include "../get_next_line/get_next_line.h"

int main(void)
{
	char *line;
	get_next_line(0, &line);
	ft_putstr(line);
	return (0);
}