#include "../inc/header.h"
#include "../inc/parser.h"
#include "../inc/token.h"

// int *count_args_pipe(char *line, int y)
// {
// 	int *args_in_pipe;
// 	int i;
// 	int x;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	x = 1;
// 	args_in_pipe = malloc(sizeof(int) * y + 1);
// 	while(line[j])
// 	{
// 		if(line[j] == ' ')
// 		{
// 			while(line[j] == ' ')
// 				j++;
// 			//x += 1;
// 		}
// 		else if(line[j] == '<' && line[j + 1] == '<')
// 			x += 1;
// 		else if(line[j] == '>' && line[j + 1] == '>')
// 			x += 1;
// 		else if(line[j] == '<')
// 			x += 1;
// 		else if(line[j] == '>')
// 			x += 1;
// 		else if (line[j] == '|')
// 		{
// 			printf("%d-----\n", x);
// 			args_in_pipe[i] = x;
// 			x = 0;
// 			i++;
// 		}
// 		j++;
// 	}
// 	args_in_pipe[i] = x;
// 	return (args_in_pipe);
// }

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


void	lexing(char *line, t_token *token)
{
	t_lexer		*lexer;
	int i;
	int x;
	int y;
	char **args;
	t_redirection *red;
	t_parser		*parse;

	x = 0;
	i = 0;
	y = 0;
	lexer = init_lexer(line);
	red = malloc (sizeof(t_redirection ) * 20);
	parse = malloc (sizeof(t_parse) * lexer->nb_pipe);
	if(lexer)
	{
		x = 0;
		i = lexer->nb_args[x];
		args = (char **)malloc(sizeof(char *) * i + 1);
		while(lexer->c)
		{
			token = get_next_token(lexer);
			i = lexer->nb_args[x];
			if(token->type == TOKEN_PIPE)
			{
				x++;
				i = lexer->nb_args[x];
				args[y] = NULL;
				parser_add_back(&parse, new_parse(args[0], args, red));
				free_array(args);
				y = 0;
				args = (char **)malloc(sizeof(char *) * i + 1);
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
			parser_add_back(&parse, new_parse(args[0], args, red));
			free_array(args);
			while (parse)
			{
				printf("cmd : %s-- args: %s --", parse->cmd, parse->args[1]);
				parse = parse->next;
			}
	}
}