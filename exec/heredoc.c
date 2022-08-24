#include "../inc/header.h"

char *random_file()
{
    static int	random;
    char		*tmp_file;

    random += 2;
    tmp_file = ft_strjoin("/dev/null", ft_itoa(random));
    return (tmp_file); 
}

int    heredoc(t_parser **parse)
{
    char *buff;
    t_parser *parser;
    t_redirection *red;
    int             end[2];

    parser = *parse;
    while (parser)
    {
        red = parser->red; 
        while(red)
        {
            if (red->type == TOKEN_HEREDOC)
            {
                pipe(end);
                while((ft_strncmp(red->file, buff, ft_strlen(red->file))))
                {
                    buff = readline("heredoc> ");
                    if ((ft_strncmp(red->file, buff, ft_strlen(red->file))))
                        ft_putendl_fd(buff, end[WRITE]);
                }
            }
            red = red->next;
        }
        parser = parser->next;
    }
    close(end[WRITE]);
	return (end[READ]);
} 
