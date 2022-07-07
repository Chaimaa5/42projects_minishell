#include "../inc/header.h"


int main()
{
    char buf[250];

    // char *read;
    chdir(getenv("HOME"));
    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);
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