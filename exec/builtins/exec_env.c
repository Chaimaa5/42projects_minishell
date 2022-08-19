#include "../../inc/header.h"

int    search_env(env_list  **env, char *key)
{
    env_list *tmp;

    tmp = *env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
            return (1);
        tmp = tmp->next;
    }
	return (0);
}

int	env_size(env_list **env)
{
	int	size;
	env_list *lst;

	lst = (*env);
	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char **env_list_to_char(env_list **env)
{
	env_list *tmp;
	char **envp;
	int i;

	tmp = (*env);
	i = 0;
	envp = malloc (sizeof(char *) * (env_size(env) + 1));
	while (tmp)
	{
		envp[i] = ft_strjoin(tmp->key, tmp->separator);
		envp[i] = ft_strjoin(envp[i], tmp->content);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

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

env_list    *env_builder(char **envp)
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
	return (env);
}

void exec_env(t_parser *parse, env_list **envp)
{
	env_list	*env;

	env = *envp;
	if (parse->args[1])
	{
		printf("env: %s: No such file or directory\n", parse->args[1]);
		return ;
	}
	while (env)
	{
		if (env->separator && env->content)
			printf("%s%s%s\n", env->key, env->separator, env->content);
		env = env->next;
	}
	exit(0);
}
