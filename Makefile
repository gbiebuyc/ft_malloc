# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 13:06:05 by gbiebuyc          #+#    #+#              #
#    Updated: 2020/01/30 13:06:11 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$(HOSTTYPE).so
SRC = src/main.c
OBJ = $(SRC:.c=.o)
CFLAGS = -I ./libft -fPIC #-Wall -Wextra -Werror
LDFLAGS = -L ./libft -lft
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -shared -o $(NAME) $(OBJ) $(LDFLAGS)
	ln -sF $(NAME) libft_malloc.so
	gcc test.c -L. -lft_malloc

clean:
	#make -C ./libft clean
	rm -rf $(OBJ)

fclean:
	#make -C ./libft fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
