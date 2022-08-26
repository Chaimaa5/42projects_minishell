#include "../../inc/header.h"

int is_numeric(char *ar)
{
    int i;

    i = 0;
    while (ar[i])
    {
        if (ar[i] < '0' || ar[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

void    exec_exit(t_parser *parser)
{
    if (!parser->args[1])
        exit(0);
    if (parser->args[2])
    {
        ft_putendl_fd("exit: too many arguments", 2);
        exit_code = 1;
    }
    if (!is_numeric(parser->args[1]))
    {
        ft_putendl_fd("exit: numeric argument required", 2);
        exit_code = 255;
    }
}