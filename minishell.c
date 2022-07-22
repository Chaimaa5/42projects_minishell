#include "inc/header.h"

int main(int ac, char **av)
{
	t_token *token;
	t_lexer *lexer;
	char *line;
	(void) ac;
	(void) av;
	while ("everything is okey")
	{
		line = readline("minishell: ");
		lexing(line);
	}
	return (0);
}
