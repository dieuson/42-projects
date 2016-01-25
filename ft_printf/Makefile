#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 17:52:26 by sgaudin           #+#    #+#              #
#    Updated: 2016/01/25 10:34:20 by dvirgile         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf

SRC = ft_printf.c

TILDE = $(SRC:.c=.c~) Makefile~ ft_printf.h.gch ft_printf.h~

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I./ -L./ -lft $(SRC) -o $(NAME)

clean:
	rm -rf $(TILDE)

fclean: clean
	rm -rf $(NAME)

re: fclean all
