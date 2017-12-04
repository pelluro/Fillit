# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:41:31 by mipham            #+#    #+#              #
#    Updated: 2017/11/14 15:11:04 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRCC = ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_strlen.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putendl.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_tolower.c ft_toupper.c \
	  ft_atoi.c ft_itoa.c \
	  ft_memset.c ft_bzero.c ft_memalloc.c ft_strnew.c ft_memdel.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strdup.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strdel.c ft_strstr.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strlcat.c\
	  ft_lstadd.c ft_lstnew.c ft_lstdel.c ft_lstmap.c ft_lstdelone.c\
	  ft_lstiter.c ft_strlen_skip_white.c ft_power.c ft_sqrt.c\
	  ft_is_prime.c ft_create_elem.c ft_strndup.c\

CC = gcc -Wall -Wextra -Werror

OBJ = $(SRCC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
