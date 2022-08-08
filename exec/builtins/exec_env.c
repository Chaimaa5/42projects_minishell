#include "../../inc/header.h"

env_list	*new_env(char *key, char *content, char *separator)
{
	env_list	*new;

	new = malloc(sizeof(env_list) * 1);
	if (!new)
		return (0);
	new->key = key;
    new->content = content;
	new->separator = separator;
	new->next = NULL;
	return (new);
}

void	env_add_back(env_list **lst, env_list *new)
{
	env_list	*n;


	n = *lst;
	if (!new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (n->next)
			n = n->next;
		n->next = new;
	}
}

env_list    **read_env(char **envp)
{
    env_list    **env;
    char        **tmp;
    int         i;

    i = 0;
	env = malloc(sizeof(env_list *));
    while(envp[i])
    {
        tmp = ft_split(envp[i], '=');
        env_add_back(env, new_env(tmp[0], tmp[1], "="));
		i++;
    }
    return (env);
}

void    env_builder(char **envp)
{
    char        **tmp;
    int         i;
	env_list	*env;

	env  = NULL;
    i = 0;
    while(envp[i])
    {
        tmp = ft_split(envp[i], '=');
        env_add_back(&env, new_env(tmp[0], tmp[1], "="));
		i++;
    }
	while(env)
	{
		printf("%s%s%s\n", env->key, env->separator, env->content);
		env = env->next;
	}
}

void exec_env(t_parser *parse, char **envp)
{
	if (parse->args[1])
	{
		printf("env: %s: No such file or directory\n", parse->args[1]);
		return ;
	}
	env_builder(envp);
}