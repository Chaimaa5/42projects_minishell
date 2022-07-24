#ifndef EXECUTIONS_H
#define EXECUTIONS_H

//biultins
void    builtins_pwd(void);
void    builtins_echo(char **arg);
void    builtins_cd(char *path);

typedef struct  env_list
{
    char            *key;
    char            *content;
    char            *separator;
    struct env_list *next;    
}   env_list;

#endif