# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlancar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/26 10:57:32 by dlancar           #+#    #+#              #
#    Updated: 2013/08/26 12:39:37 by dlancar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = main.c

all: $(NAME)

$(NAME):
	@gcc -Werror -Wall -Wextra -o $(NAME) $(SRC)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean all
