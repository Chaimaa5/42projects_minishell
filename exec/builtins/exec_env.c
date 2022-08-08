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

void    env_builder(env_list *env, char **envp)
{
    char        **tmp;
    int         i;
	
	env  = NULL;
    i = 0;
    while(envp[i])
    {
        tmp = ft_split(envp[i], '=');
        env_add_back(&env, new_env(tmp[0], tmp[1], "="));
		i++;
    }
}

void exec_env(env_list *env)
{
	env_list *tmp;

	tmp = env;
	while(tmp)
	{
		printf("%s%s%s\n", tmp->key, tmp->separator, tmp->content);
		tmp = tmp->next;
	}
}