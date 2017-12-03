# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 17:42:17 by mipham            #+#    #+#              #
#    Updated: 2017/12/01 13:55:25 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

_GREEN = $'\x1b[32m
_CYAN = $'\x1b[36m
_RED = $'\x1b[31m
_YELLOW = $'\x1b[33m
_PURPLE = $'\x1b[35m
_BLUE = $'\x1b[34m

LIB = src/libft

SRC = src/main.c\
	  src/grid.c\
	  src/check.c\
	  src/read.c\
	  src/solve.c\

INC = -I includes

OBJ = $(SRC:.c=.o)

CC = gcc

LIBPATH =	src/libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBPATH)
	@echo "${_YELLOW}Fillit generate${_END} ${_BLUE}[!${_END}]"


clean:
		rm -f $(OBJ)
			make clean -C ./src/libft/
			@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
		rm -f $(NAME)
			make fclean -C ./src/libft/
			@echo "${_RED}delete $(NAME) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean, fclean
