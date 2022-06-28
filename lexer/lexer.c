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
