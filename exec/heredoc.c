#include "../inc/header.h"
void    handle_c()
{
	exit_status = 130;
    // rl_replace_line("", 0);
    // ft_putchar_fd('\n', 1);
    // rl_on_new_line();
    // rl_redisplay();
    exit(130);
}

void    handle_d()
{
	exit_status = 1;
    // rl_replace_line("", 0);
    ft_putchar_fd('\n', 1);
    rl_on_new_line();
    // rl_redisplay();
    exit(1);
}
void handler_heredoc_sg(int end)
{
    close(end);
	// if (signal(SIGQUIT, SIG_IGN))
    // {
	// 	exit_status = 1;
    //     return;
    // }
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
            handler_heredoc_sg(end);
            buff = readline("> ");
            if ((ft_strncmp(delim, buff, ft_strlen(delim))))
                ft_putendl_fd(buff, end);
        }
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
