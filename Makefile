# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greyrol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/02 11:11:09 by greyrol           #+#    #+#              #
#    Updated: 2013/09/02 11:11:10 by greyrol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
HEADER = includes
SOURCES = srcs/
ATTRIBUTES = -Wall -Werror -Wextra
RM_DIR = /bin/rm

all:
	@gcc $(ATTRIBUTES) -O3 -I $(HEADER) -o $(NAME) $(SOURCES)main.c \
	$(SOURCES)tools.c $(SOURCES)file_desc.c $(SOURCES)map.c

fclean: clean
	@$(RM_DIR) -f $(NAME)

clean:

re: fclean all
