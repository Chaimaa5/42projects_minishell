#include "../inc/header.h"
#include "../inc/parser.h"
#include "../inc/token.h"

void free_array(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}


t_parser	**lexing(char *line, t_token *token)
{
	t_lexer		*lexer;
	int x;
	int y;
	char **args;
	t_redirection	*red;
	t_parser		**parse;


	x = 0;
	y = 0;
	lexer = init_lexer(line);
	red = malloc (sizeof(t_redirection ) * 100);
	parse = malloc (sizeof(t_parser) * 100);
	if(lexer)
	{
		x = 0;
		args = (char **)malloc(sizeof(char *) * 10);
		while(lexer->c)
		{
			token = get_next_token(lexer);
			if(token->type == TOKEN_PIPE)
			{
				x++;
				args[y] = NULL;
				parser_add_back(parse, new_parse(args[0], args, red));
				free_array(args);
				y = 0;
				args = (char **)malloc(sizeof(char *) * 10);
			}
			if(token->type == TOKEN_STR)
			{
				args[y] = token->content;
				y++;
			}
			if(token->type == TOKEN_REDIN || token->type == TOKEN_REDOUT || token->type == TOKEN_APPEND)
				red_add_back(&red, new_red(token->type, token->content));
		}
		args[y] = NULL;
		parser_add_back(parse, new_parse(args[0], args, red));
		exec_builtins(parse);
		free_array(args);		
	}
	return (parse);
}
