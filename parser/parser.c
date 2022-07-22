#include "../inc/header.h"
#include "../inc/parser.h"

void	*lexing(char *line)
{
	t_token		*token;
	t_lexer		*lexer;

	lexer = init_lexer(line);
	if(lexer)
	{
		while(lexer->c != '\0')
		{
			token = get_next_token(lexer);
			parser(token);
		}
	}
}

t_parser	*parser(t_token	*token)
{
	
}