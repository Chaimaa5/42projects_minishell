#include "inc/header.h"
#include "inc/lexer.h"
int main(int ac, char **av)
{
	t_token	token;

	char *line;
	(void) ac;
	(void) av;
	while ("everything is okey")
	{
		line = readline("minishell: ");
		lexing(line, &token);
<<<<<<< HEAD
=======

>>>>>>> 87b439deb0d7d882bc6b47bea2a1a80dafb785f6
	}
	return (0);
}
