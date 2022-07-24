#include "../../inc/header.h"

void    exec_pwd(void)
{
    char buf[250];

    // store new PWD in env list
    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);
}