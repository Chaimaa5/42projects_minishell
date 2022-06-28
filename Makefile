NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = lexer/lexer.c lexer/tokenizer.c
LIB = libft.a

all : $(NAME)

$(LIB):
	make -C libft
	cp libft/libft.a ./

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)
clean:
	rm -rf $(OBJ)
	rm -rf libft/*.o
fclean:
	rm -rf $(NAME)
	rm -rf $(LIB)
	rm -rf libft/libft.a

re: fclean all