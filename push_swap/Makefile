NAME = push_swap

LFT = ./libft
S = ./src/

SRC = $(S)push_swap.c $(S)ft_atoi.c $(S)ft_putnbr.c $(S)ft_putstr.c \
	$(S)ft_putchar.c $(S)ft_strchr.c $(S)check_push_swap.c $(S)ft_memdel.c \
	$(S)result_expected.c $(S)push_swap_moove.c $(S)tab_changes.c \
	$(S)tab_copy.c $(S)moove_a.c  $(S)moove_b.c $(S)ft_strcat.c \
	$(S)moove_aux.c ../get_next_line/get_next_line.c

DELETE = $(SRC:.c:.c~)
#DELETEALL = ./src/ *.c~ Makefile~ ./includes/*.h~
CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "\033[31mCompilation\033[0m "
	@$(CC) $(SRC) -I ./includes/push_swap.h -I ./test/get_next_line.h \
	-I ./test/libft/includes/ ./test/get_next_line/libft/libft.a -o $(NAME)
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