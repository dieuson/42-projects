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
LIBFT = ./srcs/ft_printf/libft/
FT_PRINTF = ./srcs/ft_printf/
LS = ./srcs/
FILES_LS = main.c build_list.c detection.c display.c errors.c parser.c \
sort_data.c build_simple_tab.c flag_R.c delete_data.c get_file_details.c
SRC = $(LS)main.c $(LS)build_list.c $(LS)detection.c $(LS)display.c \
$(LS)errors.c $(LS)parser.c $(LS)sort_data.c $(LS)build_simple_tab.c \
$(LS)flag_R.c $(LS)delete_data.c $(LS)get_file_details.c
BIN = $(FILES_LS:.c=.o)
INLCLUDES = $(LIBFT)libft.h ./includes/ft_ls.h

TILDE = $(SRC:.c=.c~) Makefile~

all: $(NAME)

$(NAME):
	@make -C $(FT_PRINTF)
	@printf "\033[31mCompilation $(NAME):\033[0m"
	@gcc -Wall -Wextra -Werror -g3 $(SRC) $(INCLUDES) -c
	@gcc -Wall -Wextra -Werror $(BIN) $(INCLUDES) \
	$(FT_PRINTF)libftprintf.a $(LIBFT)libft.a -o $(NAME)
	@mkdir bin_folder
	@mv $(BIN) ./bin_folder
	@printf "\033[32m done!\n\033[0m"

clean:
	@printf "\033[31mCleaning:\033[0m"
	@rm -rf $(TILDE) ./bin_folder
	@printf "\033[32m lem-in bin_folder\033[0m"
	@make -C $(FT_PRINTF) clean
	@printf "\033[32m libft bin\033[0m"
	@printf "\033[32m done!\n\033[0m"

fclean: clean
	@printf "\033[31mCleaning:\033[0m"
	@rm -rf $(NAME)
	@printf "\033[32m lem-in executable\033[0m"
	@make -C $(FT_PRINTF) fclean
	@printf "\033[32m libft.a\n\033[0m"

re: fclean all