#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define FT_INIT(type,name,value)		type name = value

typedef struct		s_docker
{
	int pointeur;
	int		**tab;
}					t_docker;

int					check_push_swap(char **elements);
int					init_tab(t_docker *data, int len, char **elements);
char				*ft_strchr(const char *s, int c);
int 				push_swap(int argc, char **elements);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
int					check_push_swap(char **elements);
int					check_doublon(int *tab);

#endif