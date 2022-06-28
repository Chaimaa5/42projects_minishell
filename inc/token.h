#ifndef TOKEN_H
#define TOKEN_H

typedef struct s_token
{
    char *content;
    enum  {
    word,
    pip,
    redin,
    redout,
    heredoc,
    append,
    }type;
}   t_token;

#endif