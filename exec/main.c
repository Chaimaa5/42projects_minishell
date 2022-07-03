#include "../inc/header.h"


int main(int argc, char **argv)
{
    (void) argc;
    builtins_pwd();
    builtins_cd(argv[1]);
    builtins_pwd();

    // char *read;
    // chdir("..");
    // getcwd(buf, sizeof(buf));
    // printf("%s\n", buf);
    // printf("PATH: %s\n", getenv("PATH"));
    // while(1)
    // {
    //     // signal(SIGINT, signal_handler);
    //     //termination signal
    //     // signal(SIGQUIT, SIG_IGN);
    //     // printf("");
    //     read = readline("minishell>>");
    //     add_history(read);
    //     // printf("%s\n", read);
    // }
}