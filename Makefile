NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RD = -lreadline -L /goinfre/cel-mhan/.brew/Library/Taps/homebrew/homebrew-core
SRC = exec/pwd.c

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(RD) $(SRC) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(NAME)

re: fclean all