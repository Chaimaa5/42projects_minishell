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
	}
	return (0);
}
