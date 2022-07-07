#include "../inc/header.h"

void    builtins_pwd(void)
{
    char buf[250];

    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);
}

void    builtins_echo(char *arg)
{
    printf("%s\n", arg);
}

void    builtins_cd(char *path)
{
    if (path == NULL)
        chdir(getenv("HOME"));
    chdir(path);
}

void    builtins_env(void)
{
    t_env   *env;

    
}
void    builtins_export()
{

}