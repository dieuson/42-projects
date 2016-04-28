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

NAME = ft_ls
LIBFT = ./srcs/libft/
LS = ./srcs/
FILES_LS = main.c
SRC = $(LS)main.c
BIN = $(FILES_LS:.c=.o)

INLCLUDES = $(LIBFT)libft.h ./includes/ft_ls.h

TILDE = $(SRC:.c=.c~) Makefile~

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@printf "\033[31mCompilation $(NAME):\033[0m"
	@gcc -Wall -Wextra -Werror -g $(SRC) $(INCLUDES) -c
	@gcc -Wall -Wextra -Werror $(BIN) $(INCLUDES) $(LIBFT)libft.a -o $(NAME)
	@mkdir bin_folder
	@mv $(BIN) ./bin_folder
	@printf "\033[32m done!\n\033[0m"

clean:
	@printf "\033[31mCleaning:\033[0m"
	@rm -rf $(TILDE) ./bin_folder
	@printf "\033[32m lem-in bin_folder\033[0m"
	@make -C $(LIBFT) clean
	@printf "\033[32m libft bin\033[0m"
	@printf "\033[32m done!\n\033[0m"

fclean: clean
	@printf "\033[31mCleaning:\033[0m"
	@rm -rf $(NAME)
	@printf "\033[32m lem-in executable\033[0m"
	@make -C $(LIBFT) fclean
	@printf "\033[32m libft.a\n\033[0m"

re: fclean all