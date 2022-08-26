#include "../inc/header.h"
#include "../inc/execution.h"

int		check_builtin(t_parser *parser)
{
	if (!ft_strncmp(parser->cmd, "cd", 3) || (!ft_strncmp(parser->cmd, "pwd", 4))
		|| !ft_strncmp(parser->cmd, "echo", 6) || !ft_strncmp(parser->cmd, "exit", 6)
		|| !ft_strncmp(parser->cmd, "env", 4) || !ft_strncmp(parser->cmd, "export", 8)
		|| !ft_strncmp(parser->cmd, "unset", 6))
			return (1);
	return (0);
}

void 	exec_builtins(t_parser *parser, t_env_list *env)
{
	if (!ft_strncmp(parser->cmd, "cd", 3) )
		exec_cd(parser->args[1], env);
    else if (!ft_strncmp(parser->cmd, "pwd", 4) || !ft_strncmp(parser->cmd, "PWD", 4))
        exec_pwd(env);
	else if (!ft_strncmp(parser->cmd, "echo", 6) || !ft_strncmp(parser->cmd, "ECHO", 6))
        exec_echo(parser);
    else if (!ft_strncmp(parser->cmd, "exit", 6))
        exec_exit(parser);
    else if (!ft_strncmp(parser->cmd, "env", 4) || !ft_strncmp(parser->cmd, "ENV", 4))
        exec_env(parser, &env);
	else if (!ft_strncmp(parser->cmd, "export", 8))
        exec_export(parser, &env);
	else if (!ft_strncmp(parser->cmd, "unset", 6))
        exec_unset(&env, parser->args[1]);
}

int parent_builtins(t_parser *parser)
{
	if (!ft_strncmp(parser->cmd, "cd", 3) && parser->flag != 1)
		return (1);
	else if (!ft_strncmp(parser->cmd, "exit", 6)
		|| !ft_strncmp(parser->cmd, "env", 4) || !ft_strncmp(parser->cmd, "export", 8)
		|| !ft_strncmp(parser->cmd, "unset", 6))
			return (1);
	return (0);
}

void execute_last_cmd(t_parser *parser, t_env_list *env, int fd_in, int *end)
{
	char	*path;
	char	**envp;

	envp = t_env_list_to_char(&env);
	path = search(envp, parser->cmd);
	if (!parser->red && parent_builtins(parser) &&  parser->flag != 1)
        exec_builtins(parser, env);
	else if (fork() == 0)
	{
		if (fd_in != 0)
			dup_end(fd_in, STDIN_FILENO);
		if (end[WRITE] > 2)
			close(end[WRITE]);
		if (!redirections(parser->red, parser->cmd) && parser->cmd)
		{
				if (check_builtin(parser))
        			exec_builtins(parser, env);
				else if (execve(path, parser->args, envp) == -1)
				{
					print_error(parser->cmd, "command not found: ", 127);
					exit(127);
				}
		}
		exit(0);
	}
}

void	launch_child(t_parser *parser, t_env_list *env, int fd_in, int *end)
{
	char	*path;
	char	**envp;

	envp = t_env_list_to_char(&env);
	path = search(envp, parser->cmd);
	if (fork() == 0)
	{
		if (fd_in != 0)
			dup_end(fd_in, STDIN_FILENO);
		dup_end(end[WRITE], STDOUT_FILENO);
		close(end[READ]);
		if (!redirections(parser->red, parser->cmd))
		{
			if (check_builtin(parser) && parser->cmd)
    		    exec_builtins(parser, env);	
			else if (parser->cmd && (execve(path, parser->args, envp) == -1))
				print_error("command not found: ", parser->cmd, 2);
		}
		exit(0);
	}
}

void	wait_child(void)
{
	int status;

	while(waitpid(-1, &status, 0) > 0)
	{
		if(WEXITSTATUS(status))
			exit_code = WEXITSTATUS(status);
	}
}

void    pipeline_execution(t_parser *parser, t_env_list **envp)
{
	int fd_in;
	t_env_list *env;
	int end[2];
	
	fd_in = 0;
	env = (*envp);
	while (parser->next)
	{
		parser->flag = 1;
		pipe(end);
		launch_child(parser, env, fd_in, end);
		close_pipe(end, fd_in);
		fd_in = end[READ];
		parser = parser->next;
		if (parser)
			parser->flag = 1;
	}
	execute_last_cmd(parser, env, fd_in, end);
	close_pipe(end, fd_in);
	wait_child();
}



