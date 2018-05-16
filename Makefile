NAME=getnextline
SRC = $(wildcard src/*.c)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL = include
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a src
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) libft.a -I $(INCL)

clean:
	cd libft && make clean

fclean:
	cd libft && make fclean
	rm -rf $(NAME)
	rm -rf libft.all

re: fclean $(NAME)

.PHONY: clean fclean re
