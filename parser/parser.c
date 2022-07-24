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
	
    if (path == NULL || !ft_strncmp(path, "~", 2))
	{
        if(!chdir(getenv("HOME")))
			printf("cd: HOME not set\n");
	}
	else
		chdir(path);
}

// void	execute(t_token *token)
// {
// 	if (!ft_strncmp(token[0].content, "pwd", 3) || !ft_strncmp(token[0].content, "PWD", 3))
// 		builtins_pwd();
// 	else if (!ft_strncmp(token[0].content, "cd", 3) || !ft_strncmp(token[0].content, "CD", 3))
// 		builtins_cd(token[1].content);
// }

void start_parse(t_token *token)
{
	if (token[0].type == TOKEN_STR)
		printf("success\n");
}

void	lexing(char *line, t_token *token)
{
	t_lexer		*lexer;
	t_token		*tokens = malloc(sizeof(t_token *) * 10);
	int			i;

	i = -1;
	lexer = init_lexer(line);
	if(lexer)
	{
		while(lexer->c != '\0')
		{
			token = get_next_token(lexer);
			if (!ft_strncmp(token->content, "cd", 3) || !ft_strncmp(token->content, "CD", 3))
				builtins_cd(get_next_token(lexer)->content);
			else if (!ft_strncmp(token[0].content, "pwd", 3) || !ft_strncmp(token[0].content, "PWD", 3))
				builtins_pwd();
			if (token->type != TOKEN_PIPE)
				tokens[++i] = (*token);
			else
				start_parse(tokens);
		}
		lexer_advance(lexer);
	}
}

