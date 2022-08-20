#include "inc/header.h"
#include "inc/lexer.h"
#include "inc/parser.h"

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
		if(ft_syntax_error(line))
			parse = lexing(line, &token);
		else
			parse = NULL;
		add_history(line);
		if(parse)
			pipeline_execution(parse, &env);
		// system("leaks minishell");
	}
	return (0);
}

