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
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) ./src/libft.a -I $(INCL)

clean:
	cd ./src/libft && make clean

fclean:
	cd ./src/libft && make fclean
	rm -rf $(NAME)
	rm -rf libft.a

re: fclean $(NAME)

.PHONY: clean fclean re
