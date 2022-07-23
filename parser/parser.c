#include "../inc/header.h"
#include "../inc/parser.h"
void    builtins_pwd(void)
{
    char buf[250];

    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);
}

void    builtins_cd(char *path)
{
    if (path == NULL)
        chdir(getenv("HOME"));
    chdir(path);
}

void	execute(t_token *token)
{
	if (!ft_strncmp(token->content, "pwd", 3) || !ft_strncmp(token->content, "PWD", 3))
		builtins_pwd();
}

void	lexing(char *line, t_token *token)
{
	t_lexer		*lexer;

	lexer = init_lexer(line);
	if(lexer)
	{
		while(lexer->c != '\0')
		{
			token = get_next_token(lexer);
			execute(token);
		}
		lexer_advance(lexer);
	}
}

