# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvirgile <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/07 09:08:44 by dvirgile          #+#    #+#              #
#    Updated: 2016/06/07 09:22:39 by dvirgile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

printf "./ft_ls:\n\n"
./ft_ls
printf "\nls:\n\n"
ls

printf "\n./ft_ls -l:\n\n"
./ft_ls -l
printf "\nls -l:\n\n"
ls -l

printf "\n./ft_ls -la:\n\n"
./ft_ls -la
printf "\nls -la:\n\n"
ls -la

printf "\n./ft_ls -t:\n\n"
./ft_ls -t
printf "\nls -t:\n\n"
ls -t

printf "\n./ft_ls -e: Option non-gerer\n\n"
./ft_ls -E
printf "\nls -e: Option non-gerer\n\n"
ls -E