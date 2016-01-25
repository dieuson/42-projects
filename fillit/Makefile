#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 17:52:26 by sgaudin           #+#    #+#              #
#    Updated: 2016/01/21 15:11:31 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = fillit_aux.c fillit_recursive.c ft_check_tetriminos_lst.c \
ft_readandmodif.c

TILDE = $(SRC:.c=.c~) Makefile~

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I./ -L./ -lft $(SRC) -o $(NAME)

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)

re: fclean all