#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/28 09:54:39 by dvirgile          #+#    #+#              #
#    Updated: 2016/06/28 14:13:33 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
DIR_SRCS = ./srcs/
DIR_GNL = $(DIR_SRCS)get_next_line/
LIBFT = ./srcs/libft/

INCLUDES = ./includes/fdf.h $(DIR_GNL)get_next_line.h

SRCS = main.c parser.c get_next_line.c build_list.c 3d_to_2d.c draw.c
BIN = $(SRCS:.c=.o) 
FDF_FILES = $(DIR_SRCS)main.c $(DIR_SRCS)parser.c $(DIR_GNL)get_next_line.c \
			$(DIR_SRCS)build_list.c $(DIR_SRCS)3d_to_2d.c $(DIR_SRCS)draw.c
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
all : NAME

NAME:
	@printf "\033[31mCompilation $(NAME):\033[0m"
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(FDF_FILES) $(INCLUDES) -c
	@$(CC) $(FLAGS) $(BIN) $(LIBFT)libft.a -lmlx  -framework OpenGL -framework AppKit -o $(NAME)
	@mkdir bin_folder
	@mv $(BIN) ./bin_folder
	@rm -rf bin_folder
	@printf "\033[32m done!\n\033[0m"

clean:
	@printf "\033[31mCleaning:\033[0m"
	@make -C $(LIBFT) clean
	@echo " Clean"
	@printf "\033[32m libft bin\033[0m"
	@printf "\033[32m done!\n\033[0m"

fclean: clean
	@printf "\033[31mCleaning:\033[0m"
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@rm -rf bin_folder
	@echo " Fclean"
	@printf "\033[32m $(NAME) executable\033[0m"
	@printf "\033[32m libft.a\n\033[0m"

re: fclean all