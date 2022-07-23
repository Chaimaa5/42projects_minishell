#ifndef HEADER_H
#define HEADER_H

#include "../libft/libft.h"
#include "lexer.h"
#include "token.h"
#include "parser.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
# include <sys/types.h>
# include <fcntl.h>

#define ERROR 0
#define MALLOC_ERR 1
#define FORK_ERR 2

typedef struct s_table{
    char *cmd;
    char *option;
    char *args;
}   t_table;

typedef struct s_env{
    char        *env;
    struct s_env *next;
}   t_env;
//  builtins
void    builtins_pwd(void);
void    builtins_echo(char *arg);
void    builtins_cd(char *path);

//redirections
void    redirections(int red, char **file);
char	*search(char **path, char *cmd);
char	*search(char **path, char *cmd);
int		find_env(char **envp, char *pwd);
char	**find_path(char **envp);
void	free_array(char **array);
int		find_path_env(char **envp, char *pwd);
#endif