#include "../inc/header.h"
#include "../inc/execution.h"

void	exec_builtins(t_parser **parse, char	**envp)
{
    if (!ft_strncmp((*parse)->cmd, "cd", 3))
        exec_cd((*parse)->args[1]);
    else if (!ft_strncmp((*parse)->cmd, "pwd", 4))
        exec_pwd();
    // else if (!ft_strncmp((*parse)->cmd, "export", 8))
    //     exec_export(env, (*parse)->args);
    // else if (!ft_strncmp((*parse)->cmd, "unset", 7))
    //     exec_unset(env, parse);
    if (!ft_strncmp((*parse)->cmd, "env", 4))
        exec_env((*parse), envp);
}

execute_last_cmd(t_parser *parser,env_list *env, int *end )
{
	char	*path;
	char	**envp;

	envp = env_list_to_char(&env);
	path = search(envp, parser->cmd);
	if (execve(path, &parser->cmd, envp) == -1)
	{
		ft_putstr_fd("command not found:", 2);
		ft_putstr_fd(parser->cmd, 2);
	}
}

void	launch_child(t_parser *parser, env_list *env, int *end)
{
	char	*path;
	char	**envp;

	envp = env_list_to_char(&env);
	path = search(envp, parser->cmd);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	if (execve(path, &parser->cmd, envp) == -1)
	{
		ft_putstr_fd("command not found:", 2);
		ft_putstr_fd(parser->cmd, 2);
	}
}

void    execute(t_parser *parser, char **envp)
{
	int pid;
	env_list *env;
	int end[2];

	env = env_builder(envp);
	while (parser->next)
	{
		pid = fork();
		pipe(end);
		if (pid == 0)
			launch_child(parser, env, end);
		parser = parser->next;
	}
	execute_last_cmd(parser);
}



