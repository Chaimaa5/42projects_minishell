#include "inc/header.h"
#include "struct.h"

void    handler()
{
    // rl_replace_line("", 0);
    ft_putchar_fd('\n', 1);
    rl_on_new_line();
    rl_redisplay();
    return;
}
void hd_sg()
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}

int main(int ac, char **av, char **envp)
{
	t_token		token;
	t_parser	*parse;
	t_env_list	*env;
	env = env_builder(envp);
	char *line;
	(void) ac;
	(void) av;
	while ("everything is okey")
	{
		// hd_sg();
		line = readline("minishell: ");
		if (!line)
		{
			write(1, "exit\n", 6);
			exit(0);
		}
		if(ft_syntax_error(line))
			parse = lexing(line, &token, env);
		else
			parse = NULL;
		add_history(line);
		if(parse)
		{
			heredoc(&parse);
			pipeline_execution(parse, &env);
		}
		// free(line);
		// free(parse->cmd);
		// free(parse);
	}
	return (0);
}

