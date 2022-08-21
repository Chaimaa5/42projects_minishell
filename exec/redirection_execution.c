#include "../inc/header.h"

int    redirection_in_from(t_redirection *red)
{
	if (access(red->file, F_OK) == 0)
		return (open(red->file, O_RDONLY, 0777));
	else
	{
        perror("file");
		return (-1);
	}
}

int    redirection_out_to(t_redirection *red)
{
    int output = 90;

    if (red->type == TOKEN_REDOUT)
        output = open(red->file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else if (red->type == TOKEN_APPEND)
        output = open(red->file, O_WRONLY | O_CREAT | O_APPEND, 0777);
    return (output);
}

void    redirections(t_redirection *red, char *cmd)
{
    int output = -1;
    int input = -2;

    if (!red)
        return ;
    while (red)
    {
        if (red->type == TOKEN_REDIN)
            input = redirection_in_from(red);
        else if (red->type == TOKEN_APPEND || red->type == TOKEN_REDOUT)
            output = redirection_out_to(red);
        if  (!red->next && cmd)
        {
            if (output != -1)
            {
                dup2(output, STDOUT_FILENO);
                close(output);
            }
            else if (input != -2)
            {
                dup2(input, STDIN_FILENO);
                close(input);
            }
        }
        red = red->next;
    }
}
