#include "../inc/header.h"

int random_file()
{
    static int file;

    file += 1;
    return (file); 
}
void    heredoc(t_parser **parse)
{
    // int file = random_file();
    int tmp_file;
    char *buff;
    t_parser *parser;
    t_redirection *red;

    parser = *parse;
    tmp_file = open("tmp/file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    while (parser)
    {
        red = parser->red; 
        while(red)
        {
            if (red->type == TOKEN_HEREDOC)
            {
                buff = readline("heredoc> ");
                while((ft_strncmp(red->file, buff, ft_strlen(buff))))
                {
                    buff = readline("heredoc> ");
		            add_history(buff);
                    ft_putendl_fd(buff, tmp_file);
                }
            }
            red = red->next;
        }
        parser = parser->next;
    }
} 
