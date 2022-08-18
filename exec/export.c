#include "../inc/header.h"
#include "../inc/execution.h"

int		check_builtin(t_parser *parser)
{
	if (!ft_strncmp(parser->cmd, "cd", 3))
		return (1);
	else if (!ft_strncmp(parser->cmd, "pwd", 4))
		return (1);
	else if (!ft_strncmp(parser->cmd, "echo", 6))
		return (1);
	else if (!ft_strncmp(parser->cmd, "export", 8))
		return (1);
	else if (!ft_strncmp(parser->cmd, "exit", 6))
		return (1);
	return (0);
}

void	exec_builtins(t_parser **parse,  env_list **env)
{
    if (!ft_strncmp((*parse)->cmd, "cd", 3))
        exec_cd((*parse)->args[1]);
    else if (!ft_strncmp((*parse)->cmd, "pwd", 4))
        exec_pwd();
    else if (!ft_strncmp((*parse)->cmd, "export", 8))
        exec_export((*parse), env);
	else if (!ft_strncmp((*parse)->cmd, "echo", 6))
        exec_echo((*parse));
    else if (!ft_strncmp((*parse)->cmd, "exit", 6))
        exec_exit(*parse);
    if (!ft_strncmp((*parse)->cmd, "env", 4))
        exec_env((*parse), env);
	exit(0);
}

void 	execute(t_parser *parser, char *path, char **envp, env_list *env)
{
	if (!ft_strncmp(parser->cmd, "export", 8))
        exec_export(parser, &env);
	else if (execve(path, parser->args, envp) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(parser->cmd, 2);
		exit(127);
	}
}

void execute_last_cmd(t_parser *parser, env_list *env, int write_in)
{
	char	*path;
	char	**envp;
	int pid;
	int status;

	envp = env_list_to_char(&env);
	path = search(envp, parser->cmd);
	pid = fork();
	waitpid(pid, &status, 0);
	if (pid == 0)
	{
		if (write_in != 0)
		{
			dup2(write_in, STDIN_FILENO);
			close(write_in);
		}
		redirections(parser->red);
		execute(parser, path, envp, env);
	}
}
void	launch_child(t_parser *parser, env_list *env, int write_in, int *end)
{
	char	*path;
	char	**envp;
	envp = env_list_to_char(&env);
	path = search(envp, parser->cmd);
	if (write_in != 0)
	{
		dup2(write_in, STDIN_FILENO);
		close(write_in);
	}
	dup2(end[WRITE], STDOUT_FILENO);
	close(end[WRITE]);
	redirections(parser->red);
	execute(parser, path, envp, env);
}

void    pipeline_execution(t_parser *parser, env_list **envp)
{
	pid_t pid;
	env_list *env;
	int end[2];
	int	write_in;
	int status;
	
	write_in = 0;
	env = (*envp);
	while (parser->next)
	{
		pipe(end);
		pid = fork();
		if (pid == 0)
			launch_child(parser, env, write_in, end);
		write_in = end[READ];
		close(end[WRITE]);
		parser = parser->next;
	}
	execute_last_cmd(parser, env, write_in);
	while(waitpid(-1, &status, 0) > 0);
}



