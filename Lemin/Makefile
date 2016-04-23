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

NAME = lem-in
GNL = ./srcs/get_next_line/
LIBFT = ./srcs/libft/
LEMIN = ./srcs/
FILES_GNL = get_next_line.c
FILES_LEMIN = main.c parser.c build_list.c create_way_tab.c\
moove_ant.c  create_neighbor_tab.c display_functions.c create_way_tools.c \
ant_routes.c moove_ant_tools.c del_over_ways.c
SRC = $(GNL)$(FILES_GNL) $(LEMIN)main.c $(LEMIN)parser.c $(LEMIN)build_list.c\
$(LEMIN)create_way_tab.c $(LEMIN)create_neighbor_tab.c $(LEMIN)moove_ant.c \
$(LEMIN)display_functions.c $(LEMIN)create_way_tools.c $(LEMIN)ant_routes.c \
$(LEMIN)moove_ant_tools.c $(LEMIN)del_over_ways.c
BIN = $(FILES_GNL:.c=.o) $(FILES_LEMIN:.c=.o)

INLCLUDES = $(LIBFT)libft.h $(GNL)get_next_line.h ./includes/lem-in.h 	

TILDE = $(SRC:.c=.c~) Makefile~

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@printf "\033[31mCompilation $(NAME):\033[0m"
	@gcc -Wall -Wextra -Werror $(SRC) $(INCLUDES) -c
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