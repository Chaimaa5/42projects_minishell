NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = lexer/lexer.c
LIB = libft.a

all : $(NAME)

$(LIB):
	make -C libft
	cp libft/libft.a ./

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(NAME)

re: fclean all