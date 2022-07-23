#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct s_lexer{
    char			c;
    char			*line;
    unsigned int	pos;
<<<<<<< HEAD
    int q_pos;
    int cunt_arg;
=======
    int             q_pos;
    int             cunt_pp;
>>>>>>> ad5980264e2cc750578aa93fab268baabaec3c2b
} t_lexer;

typedef struct s_parse{
    char *cmd;
    char *arg;
    char *ops;
    char *pipe;
    char *red;
    struct s_parse *next;
}   t_parse;

t_lexer *init_lexer(char *line);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_whitespaces(t_lexer *lexer);
void    get_next_token(t_lexer *lexer, t_token *token);
void    collect_string(t_lexer *lexer, t_token **token);
char    *get_char_as_string(t_lexer *lexer);
<<<<<<< HEAD
t_token *advance_token(t_lexer *lexer, t_token *token);
t_token *collect_cmd(t_lexer *lexer);
t_token *collect_red(t_lexer *lexer);
<<<<<<< HEAD
=======
=======
void    advance_token(t_lexer *lexer, t_token *token, t_token **tokens);
void	collect_cmd(t_lexer *lexer, t_token **token);
void    collect_red(t_lexer *lexer, t_token **token);
>>>>>>> 87b439deb0d7d882bc6b47bea2a1a80dafb785f6
void	lexing(char *line, t_token *token);
>>>>>>> ad5980264e2cc750578aa93fab268baabaec3c2b

#endif