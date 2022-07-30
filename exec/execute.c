#include "../inc/header.h"
#include "../inc/execution.h"

void	exec_builtins(t_parser **parse)
{
    if (!ft_strncmp((*parse)->cmd, "cd", 3))
        exec_cd((*parse)->args[1]);
    else if (!ft_strncmp((*parse)->cmd, "pwd", 4))
        exec_pwd();
    // else if (!ft_strncmp((*parse)->cmd, "export", 7))
    //     exec_export(env, (*parse)->args);
    // else if (!ft_strncmp((*parse)->cmd, "unset", 6))
    //     exec_unset(env, parse);
    // else if (!ft_strncmp((*parse)->cmd, "env", 3))
    //     exec_env(env, envp);
}

// execute_last_cmd()
// {

// }

execute_pipeline(t_parser *parse)
{
        while (parse->cmd)
        {
            launch_child(parse);

        }
        execute_last_cmd(parse);
}
