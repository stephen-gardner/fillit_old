#!/usr/bin/make -f
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = \
	memalloc\
	memcpy\
	memmove\
	memset\
	putchar_fd\
	putendl\
	putendl_fd\
	putstr_fd\
	strlen\
	strncmp\
	strnequ
OBJ = $(patsubst %, ft_%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all
