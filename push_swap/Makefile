#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 16:08:35 by dvirgile          #+#    #+#              #
#    Updated: 2016/03/24 16:08:38 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
S = ./src/

SRC = $(S)push_swap.c $(S)ft_atoi.c $(S)ft_putnbr.c $(S)ft_putstr.c \
	$(S)ft_putchar.c $(S)ft_strchr.c $(S)check_push_swap.c $(S)ft_memdel.c \
	$(S)push_swap_moove.c $(S)tab_changes.c \
	$(S)moove_a.c  $(S)moove_b.c \
	$(S)moove_aux.c $(S)ft_strcmp.c $(S)ft_putcolor.c \

DELETE = $(SRC:.c:.c~)
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation\033[0m "
	@$(CC) $(SRC) -I ./includes/push_swap.h -o $(NAME)
	@echo "\033[32m[OK]\033[0m"

clean:
	@printf "\033[31mNettoyage des dossiers\033[0m "
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m"

fclean: clean
	@printf "\033[31mNettoyage de tous les dossiers\033[0m "
	@rm -rf $(DELETE)
	@echo "\033[32m[OK]\033[0m"

push:
	@git add .
	@git commit -m "Makefile pushed"
	@git push

re: fclean all