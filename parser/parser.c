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
			i++;
	}
	return(i);
}

char **add_args_to_list(char **args, t_token *token)
{
	char **new_args;
	int i;
	int count;

	count = count_args(args);
	i = -1;
	new_args = malloc(sizeof(char *) * (count + 2));
	while(++i < count)
		new_args[i] = args[i];
	free(args);
	new_args[i++] = token->content;
	new_args[i] = NULL;
	return (new_args);
}

// void add_parse(t_parser *parse, char *cmd, char **args)
// {
// 	t_parser *tmp;

// }

void lexing(char *line, t_token *token)
{
	t_lexer *lexer;
	t_parser *parse;
	t_parser *tmp;
	char *cmd;
	char **arg;
	cmd = NULL;
	arg = NULL;
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
				tmp = new_parse(cmd , arg);
				parser_add_back(&parse, tmp);
				cmd = NULL;
				arg = NULL;
			}
		}
		if(!lexer->c)
		{
			tmp = new_parse(cmd , arg);
			parser_add_back(&parse, tmp);
		}
	}
}
