#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 17:52:26 by sgaudin           #+#    #+#              #
#    Updated: 2016/02/09 09:52:04 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = get_next_line.c ../srcs/main.c
BIN = get_next_line.o main.o

TILDE = $(SRC:.c=.c~) Makefile~ get_next_line.h~ get_next_line.h.gch

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation de la libft:\033[0m"
	@make -C libft
	@printf "\033[32m done!\n\033[0m"
	@printf "\033[31mCompilation GNL:\033[0m"
	@gcc -Wall -Wextra -Werror $(SRC) ./libft/includes/libft.h -c
	@gcc -Wall -Wextra -Werror $(BIN) ./libft/libft.a ./libft/includes/libft.h -o get_next_line
	@printf "\033[32m done!\n\033[0m"

clean:
	@rm -rf $(TILDE) $(BIN)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all