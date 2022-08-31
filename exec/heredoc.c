#include "../inc/header.h"
void    handle_c()
{
	exit_status = 130;
    exit(130);
}

void handler_heredoc_sg()
{
	signal(SIGINT, handle_c);
}
void heredoc_implementation(char *delim, int end)
{
    char *buff;

    buff = NULL;
    if (fork() == 0)
    {
        while((ft_strncmp(delim, buff, ft_strlen(delim))))
        {
            handler_heredoc_sg();
            buff = readline("> ");
            if (!buff)
                exit(1);
            if ((ft_strncmp(delim, buff, ft_strlen(delim))))
                ft_putendl_fd(buff, end);
        }
        exit(0);
    }
}

void    heredoc(t_parser **parse)
{
    t_parser *parser;
    t_redirection *red;
    int end[2];
    parser = *parse;
    while (parser)
    {
        red = parser->red; 
        while(red)
        {
            if (red->type == TOKEN_HEREDOC)
            {
                pipe(end);
                heredoc_implementation(red->file, end[WRITE]);
                red->end = end[READ];
                close(end[WRITE]);
            }
            red = red->next;
        }
        parser = parser->next;
    }
} 
