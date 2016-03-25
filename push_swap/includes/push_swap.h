/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:53:11 by dvirgile          #+#    #+#             */
/*   Updated: 2016/03/25 14:10:53 by dvirgile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define FT_INIT(type,name,value)		type name = value

typedef struct		s_docker
{
	int				len_a;
	int				len_b;
	int				last_a;
	int				last_b;
	int				**tab;
	int				empty;
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
		rrr}		enum_moove;
}					t_docker;

void				print_moove(t_docker *data);
void				ft_putcolor(t_docker *data, int ligne, int colonne);
int					ft_strcmp(const char *s1, const char *s2);
int					verif_tab(int *tab, t_docker *data, int len);
int					init_tab(t_docker *data, int len, char **elements);
int					check_push_swap(char **elements);
int					push_swap(int argc, char **elements);
int					check_doublon(int *tab, int len);
void				ft_print_tab(int **tab, t_docker *data);
void				ft_memdel_tab(t_docker *data);

int					distrib(int **tab, t_docker *data);
int					resize_tab(t_docker *data, int len_a, int len_b);
int					m_pa(t_docker *data);
int					m_sa(t_docker *data);
int					m_ra(t_docker *data);
int					m_rra(t_docker *data);
int					m_pb(t_docker *data);
int					m_sb(t_docker *data);
int					m_rb(t_docker *data);
int					m_rrb(t_docker *data);
int					m_ss(t_docker *data);
int					m_rr(t_docker *data);
int					m_rrr(t_docker *data);

void				ft_memdel(void **ap);
char				*ft_strchr(const char *s, int c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
long int			ft_atoi(const char *str);
void				ft_putchar(char c);

#endif
