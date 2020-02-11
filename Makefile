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
SRC = src/malloc.c \
	src/calloc.c \
	src/realloc.c \
	src/free.c \
	src/utils.c \
	src/init_node.c \
	src/show_alloc_mem.c
OBJ = $(SRC:.c=.o)
CFLAGS = -I ./libft -fPIC -Wall -Wextra -Werror
LDFLAGS = -L ./libft -lft
.PHONY: all test clean fclean re

all: $(NAME)

test: $(NAME) test.out

test.out: src/test.c
	$(CC) $^ -o $@ ./libft/libft.a ./libft_malloc.so

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -shared -o $(NAME) $(OBJ) $(LDFLAGS)
	ln -sf $(NAME) libft_malloc.so

clean:
	make -C ./libft clean
	rm -rf $(OBJ)

fclean:
	make -C ./libft fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)
	rm -rf libft_malloc.so
	rm -rf test.out

re: fclean all
