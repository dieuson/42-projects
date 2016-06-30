# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:06:17 by alhote            #+#    #+#              #
#    Updated: 2016/06/27 10:45:08 by dvirgile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_SRCS = ./srcs/
INCLUDES = ./includes/minishell.h

FLAGS = -g -Wall -Wextra -Werror
CC = gcc

FILES = main.c
SRCS = $(DIR_SRCS)main.c
BIN = $(SRCS:.c=.o)

all: $(NAME)


$(NAME):
	@printf "\033[31mCompilation $(NAME):\033[0m"

	
clean: 
	@printf "\033[31mCleaning:\033[0m"

fclean: clean
	@printf "\033[31mCleaning:\033[0m"

re: fclean all
