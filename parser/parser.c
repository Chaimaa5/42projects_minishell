#include "../inc/header.h"
#include "../inc/parser.h"

void	lexing(char *line, t_token **token)
{
	t_lexer		*lexer;

	lexer = init_lexer(line);

	if(lexer)
	{
			get_next_token(lexer, token);
			while ((*token))
			{
				printf("%s--%d\n", (*token)->content, (*token)->type);
				(*token) = (*token)->next;
				printf("---\n");
			}
			// parser(token, lexer);
	}
}

// t_parser	*parser(t_token	*token, t_lexer *lexer)
// {
// 	int i;

// }