# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 16:56:17 by hjo               #+#    #+#              #
#    Updated: 2018/04/17 16:56:18 by hjo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline
CC = gcc
CFLAGS = -Wextra -Wall -Werror -I -includes
SRC = $(wildcard src/* .c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a .
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) libft.a

clean:
	-cd src/libft && make clean

fclean: clean
	-cd src/libft && make fclean
	-rm -rf $(NAME)
	-rm -f libft.a

re: fclean $(NAME)

.PHONY: clean fclean re
