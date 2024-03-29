/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:01:15 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/09/03 01:01:18 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	heredoc_implementation(char *delim, int end)
{
	char	*buff;
	pid_t	pid;

	buff = NULL;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		while ((ft_strncmp(delim, buff, (ft_strlen(delim) + 1))))
		{
			signal(SIGINT, SIG_DFL);
			buff = readline("> ");
			if (!buff)
			{
				free(buff);
				exit(0);
			}
			if ((ft_strncmp(delim, buff, ft_strlen(delim))))
				ft_putendl_fd(buff, end);
			free(buff);
		}
		exit(0);
	}
}

void	heredoc(t_parser **parse)
{
	t_parser		*parser;
	t_redirection	*red;
	int				end[2];

	parser = *parse;
	while (parser)
	{
		red = parser->red;
		while (red)
		{
			if (red->type == TOKEN_HEREDOC)
			{
				pipe(end);
				heredoc_implementation(red->file, end[WRITE]);
				red->end = end[READ];
				close(end[WRITE]);
				wait_child(1);
			}
			red = red->next;
		}
		parser = parser->next;
	}
}
