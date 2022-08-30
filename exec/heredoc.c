#include "../inc/header.h"
void    handle()
{
	exit_status = 130;
    rl_replace_line("", 0);
    ft_putchar_fd('\n', 1);
    rl_on_new_line();
    rl_redisplay();
    return;
}

void handler_heredoc_sg()
{
	if (signal(SIGQUIT, SIG_IGN))
		exit_status = 1;
	signal(SIGINT, handle);
}
void heredoc_implementation(char *delim, int end)
{
    char *buff;

    buff = NULL;
 
        while((ft_strncmp(delim, buff, ft_strlen(delim))))
        {
            // handler_heredoc_sg();
            buff = readline("> ");
            if ((ft_strncmp(delim, buff, ft_strlen(delim))))
                ft_putendl_fd(buff, end);
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
