#include "../inc/lexer.h"
#include "../inc/header.h"
#include "../inc/token.h"

t_lexer *init_lexer(char *line)
{
    t_lexer *lexer;

    lexer = malloc(sizeof(t_lexer));
    lexer->line = line;
    lexer->pos = 0;
    lexer->c = line[lexer->pos];
    return (lexer);
}

void    lexer_advance(t_lexer *lexer)
{
    if (lexer->c != '\0' && lexer->pos < ft_strlen(lexer->line))
    {
        lexer->pos++;
        lexer->c = lexer->line[lexer->pos];
    }
}

void	lexer_skip_whitespaces(t_lexer *lexer)
{
    while (lexer->c == ' ')
        lexer_advance(lexer);
}

t_token *get_next_token(t_lexer *lexer)
{
    while (lexer->c != '\0' && lexer->pos < ft_strlen(lexer->line))
    {
        if (lexer->c == ' ')
            lexer_skip_whitespaces(lexer);
        if (lexer->c == '"')
            return (collect_string(lexer));
        if(ft_isalnum(lexer->c))
            return (collect_cmd(lexer));
        if (lexer->c == '<' && lexer->c++ == '<')
        {
            lexer_advance(lexer);
            return (advance_token(lexer, init_token(TOKEN_HEREDOC, "<<")));
        }
        if (lexer->c == '>' && lexer->c++ == '>')
        {
            lexer_advance(lexer);
            return (advance_token(lexer, init_token(TOKEN_APPEND, ">>")));
        }
        if (lexer->c == '<')
            return (advance_token(lexer, init_token(TOKEN_REDOUT, get_char_as_string(lexer))));
        else if (lexer->c == '>')
            return (advance_token(lexer, init_token(TOKEN_REDIN, get_char_as_string(lexer))));
        else if (lexer->c == '|')
            return (advance_token(lexer, init_token(TOKEN_PIPE, get_char_as_string(lexer))));
    }
    return (NULL);
}

t_token *collect_string(t_lexer *lexer)
{
    char *value;
    char *s;

    value = malloc(2 * sizeof(char));
    value[0] = '\0';
    lexer_advance(lexer);
    while (lexer->c != '"')
    {
        s = get_char_as_string(lexer);
        value = ft_strjoin(value, s);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);
    return(init_token(TOKEN_STR, value));
}

char *get_char_as_string(t_lexer *lexer)
{
    char *str;

    str = malloc(2 * sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    return(str);
}

t_token *collect_cmd(t_lexer *lexer)
{
    char *value;
    char *s;

    value = malloc(2 * sizeof(char));
    value[0] = '\0';
    while (ft_isalnum(lexer->c))
    {
        s = get_char_as_string(lexer);
        ft_strcat(value, s);
        lexer_advance(lexer); 
    }
    lexer_advance(lexer); 
    return(init_token(TOKEN_CMD, value));
} 

t_token *advance_token(t_lexer *lexer, t_token *token)
{
    lexer_advance(lexer);
    return (token);
}

char    *join_args(int ac, char **av)
{
    int i;
    char *line;

    i = 1;
    line = " ";
    while (i < ac)
    {
        line = ft_strjoin(line, av[i]);
        line = ft_strjoin(line, " ");
        i++;
    }
    return (line);
}
int main(int ac, char **av)
{
    t_token *token;
    t_lexer *lexer;
    char *line;

    line = join_args(ac, av);
    token = (void*)0;
    lexer = init_lexer(line);
    while ((token = get_next_token(lexer)))
        printf("TOKEN(%d, %s)\n", token->type, token->content);
    return (0);
}