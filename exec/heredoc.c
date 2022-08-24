#include "../inc/header.h"

void heredoc_implementation(char *delim, int *end)
{
    char *buff;

    buff = NULL;
    while((ft_strncmp(delim, buff, ft_strlen(delim))))
    {
        buff = readline("heredoc> ");
        if ((ft_strncmp(delim, buff, ft_strlen(delim))))
            ft_putendl_fd(buff, end[WRITE]);
    }
}
int    heredoc(t_parser **parse)
{
    t_parser *parser;
    t_redirection *red;
    int end[2];
    parser = *parse;
        pipe(end);
    while (parser)
    {
        red = parser->red; 
        while(red)
        {
            if (red->type == TOKEN_HEREDOC)
                heredoc_implementation(red->file, end);
            red = red->next;
        }
        parser = parser->next;
    }
        close(end[WRITE]);
	return (end[READ]);
} 
