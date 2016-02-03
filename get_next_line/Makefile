
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 17:52:26 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/03 14:43:06 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = get_next_line.c main.c

TILDE = $(SRC:.c=.c~) Makefile~ get_next_line.h~ get_next_line.h.gch *.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o a.out main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean
re: fclean all