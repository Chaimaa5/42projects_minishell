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

    parser = *parse;
    tmp_file = open("tmp/file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    while (parser)
    {
        while(parser->red)
        {
            if (parser->red->type == TOKEN_HEREDOC)
            {
                buff = readline("heredoc> ");
                while((ft_strncmp(parser->args[0], buff, ft_strlen(buff))))
                {
                    buff = readline("heredoc> ");
		            add_history(buff);
                    ft_putendl_fd(buff, tmp_file);
                }
            }
            parser->red = parser->red->next;
        }
        parser = parser->next;
    }
    
}