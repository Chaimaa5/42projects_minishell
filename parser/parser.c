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

int count_args(char **args)
{
	int i;
	i = 0;

	if(args)
	{
		while(args[i])
		{
			// printf("%s\n", args[i]);
			i++;
		}
	}
	return(i);
}

char **add_args_to_list(char **args, t_token *token)
{
	char **new_args;
	int i;
	int count;

	count = count_args(args);
	i = 0;
	new_args = malloc(sizeof(char *) * (count + 2));
	while(i < count)
	{
		new_args[i] = args[i];
		i++;
	}
	free(args);
	new_args[i++] = token->content;
	new_args[i] = NULL;
	return (new_args);
}
// cmd s | cmd1 sdd | cmd2 sdsd
// void add_parse(t_token *token, t_parser **parse)
// {
// 	// char *cmd = parser_last(parse)->cmd;
// 	// char **arg = parser_last(parse)->args;
// 	if(token->type == TOKEN_STR)
// 	{
// 		if(!parser_last(parse)->cmd)
// 		{
// 			parser_last(parse)->cmd = ft_strdup(token->content);
// 		}
// 		parser_last(parse)->args = add_args_to_list(parser_last(parse)->args , token);
// 	}
// 	else if(token->type == TOKEN_PIPE)
// 	{
// 		parser_add_back(parse,new_parse() );
// 	}
// }

void lexing(char *line, t_token *token)
{
	t_lexer *lexer;
	t_parser *parse;
	char *cmd = NULL;
	char **arg = NULL;
	parse = NULL;
	
	lexer = init_lexer(line);
	if(lexer)
	{
		while (lexer->c)
		{
			token = get_next_token(lexer);
			if(token->type == TOKEN_STR)
			{
				if(!cmd)
					cmd = ft_strdup(token->content);
				arg = add_args_to_list(arg , token);
			}
			else if (token->type == TOKEN_PIPE)
			{
				t_parser *tmp =  new_parse(cmd , arg);
				parser_add_back(&parse, tmp);
				cmd = NULL;
				arg  = NULL;
			}			
		}
		if(!lexer->c)
		{
			t_parser *tmp =  new_parse(cmd , arg);
			parser_add_back(&parse, tmp);
		}
	}
}
