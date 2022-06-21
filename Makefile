NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RD = -lreadline 
SRC = exec/pwd.c

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(RD) $(SRC) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(NAME)

re: fclean all