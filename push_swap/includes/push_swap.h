#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define FT_INIT(type,name,value)		type name = value

typedef struct		s_docker
{
	int 			len_a;
	int 			len_b;
	int 			neighbourg_less;
	int 			neighbourg_more;
	int 			**tab;
	int 			*pos_tab;
	enum {
		sa = 1,
		sb,
		ss,
		pb,
		pa,
		ra,
		rb,
		rr,
		rra,
		rrb,
		rrr
		}			enum_moove;
}					t_docker;

int					check_push_swap(char **elements);
int 				push_swap(int argc, char **elements);
int					check_push_swap(char **elements);
int					check_doublon(int *tab);
void				ft_print_tab(int **tab);
int 				*sort_int_tab(int *tab);
void				print_result(int *result);
void				ft_print_tab(int **tab);
int  				distrib(int **tab, t_docker *data);
int					m_sa(t_docker *data);
int					m_sb(t_docker *data);
void		 		ft_memdel_tab(t_docker *data);


void				ft_memdel(void **ap);
char				*ft_strchr(const char *s, int c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
int					ft_atoi(const char *str);
void				ft_putchar(char c);

#endif