#include "../../inc/header.h"

void    exec_pwd(t_env_list *env)
{
    char buf[250];
    (void)env;

    // if (getcwd(buf, sizeof(buf)) != get_env(&env, "PWD"))
    //     printf("%s\n", get_env(&env, "PWD"));
    if (getcwd(buf, sizeof(buf)))
        printf("%s\n", buf);
    exit(0);
}