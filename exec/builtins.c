#include "../inc/header.h"
// void    signal_handler(int sig)
// {
//     if (sig == SIGINT)
//     {
//         printf("\n");
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//     }
// }

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
    chdir(path);
}

void    builtins_export()