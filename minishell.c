#include "inc/header.h"
#include "inc/lexer.h"
#include "inc/parser.h"

int ft_count_elems(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void ft_2d(char **str)
{
	int i = 0;
	while(str[i])
		printf("%s <<\n", str[i++]);
}


int main(int ac, char **av, char **envp)
{
	t_token		token;
	t_parser	*parse;
	env_list	*env;

	env = env_builder(envp);
	char *line;
	(void) ac;
	(void) av;
	while ("everything is okey")
	{
		line = readline("minishell: ");
		add_history(line);
		parse = lexing(line, &token);
		if(parse)
			pipeline_execution(parse, &env);
	}
	return (0);
}

