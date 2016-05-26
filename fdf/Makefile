# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhote <alhote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 19:06:17 by alhote            #+#    #+#              #
#    Updated: 2016/05/19 16:22:58 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FDF = ./srcs/
GNL = ./srcs/get_next_line/
LIBFT = ./srcs/libft/
INCLUDES = ./includes/mlx.h $(GNL)get_next_line.h
OS = $(shell uname)
CC = gcc
CFLAGS  = -g -Wall -Wextra -Werror -Ofast

FDF_FILES = main.c get_next_line.c
SRCS = $(FDF)main.c $(GNL)get_next_line.c

BIN = $(FDF_FILES:.c=.o)
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	@printf "\033[31mCompilation $(NAME):\033[0m"
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) -c
ifeq ($(OS),Darwin)
	@$(CC) $(CFLAGS) $(BIN) ./srcs/libft/libft.a -lm -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
else ifeq ($(OS),Linux)
	@$(CC) $(CFLAGS) $(BIN) ./srcs/libft/libft.a -lm -lmlx -lXext -lX11 -lm \
	-o $(NAME)
endif
	@mkdir bin_folder
	@mv $(BIN) ./bin_folder
	@rm -rf bin_folder
	@printf "\033[32m done!\n\033[0m"

clean:
	@printf "\033[31mCleaning:\033[0m"
	@make -C $(LIBFT) clean
	@echo "Clean"
	@printf "\033[32m libft bin\033[0m"
	@printf "\033[32m done!\n\033[0m"

fclean: clean
	@printf "\033[31mCleaning:\033[0m"
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "Fclean"
	@printf "\033[32m $(NAME) executable\033[0m"
	@printf "\033[32m libft.a\n\033[0m"

re: fclean all
