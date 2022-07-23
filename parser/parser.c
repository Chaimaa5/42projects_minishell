#include "../inc/header.h"
#include "../inc/parser.h"

void	lexing(char *line, t_token *token)
{
	t_lexer		*lexer;

	lexer = init_lexer(line);
	if(lexer)
	{
		token = get_next_token(lexer);
		printf("%s--%d\n", token->content, token->type);
	}
}
