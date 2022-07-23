#include "../inc/header.h"
#include "../inc/parser.h"

void	lexing(char *line, t_token *token)
{
	t_lexer		*lexer;
	t_token		*tmp;

	lexer = init_lexer(line);
	if(lexer)
	{
		get_next_token(lexer, token);
		tmp = token;
		while (tmp)
		{
			printf("%s--%d\n", tmp->content, tmp->type);
			tmp = tmp->next;
		}
		lstclear(&token);
	}
}
