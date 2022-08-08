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
	env_list	env;
	t_parser	parse;

	char *line;
	(void) ac;
	(void) av;
	while ("everything is okey")
	{
		line = readline("minishell: ");
		if(ft_syntax_error(line))
			lexing(line, &token);
		else
			printf("SYNTAX ERROR\n");
		env_builder(&env, envp);
		execute(&parse, &env);
	}
	return (0);
}

