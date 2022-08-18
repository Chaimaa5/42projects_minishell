#include "../../inc/header.h"

int	ft_isalnumdash(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || (c == '_'))
		return (1);
	return (0);
}

int     check_key(char *key)
{
    int i;

    i = 1;
    if (ft_isalpha(key[0]) || key[0] == '_')
    {
        while(key[i])
        {
            if (!ft_isalnumdash(key[i]))
            {
                printf("export: %s: not a valid identifier\n", key);
                return (0);
            }
            i++;
        }
    }
    else
    {
        printf("export: %s: event not found\n", key);
        return (0);
    }
    return (1);
}

env_list	*env_last(env_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


void set_export(env_list *env,  char **args)
{
    char    **temp = NULL;
    int i;
    env_list *tmp;
    i = 1;
    while(args[i])
    {
        if (check_key(args[i]))
        {
            if (!ft_strchr(*args, '='))
            {
                temp = ft_split(args[1], '=');
                if (!temp[1])
                    env_add_back(&env, new_env(temp[0], temp[1], "="));
                else
                    env_add_back(&env, new_env(temp[0], "\"\"", "="));
            }
            else
            {
                tmp = new_env(args[1], NULL, NULL);
                env_add_back(&env, tmp);
            }    
        }
        i++;
    }
}

void    replace_value(env_list  **env, char *key, char *value)
{
    env_list *tmp;

    tmp = *env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen(key)))
            tmp->content = value;
        tmp = tmp->next;
    }
}

void exec_export(t_parser *parse, env_list **envp)
{
	env_list	*env;

	env = *envp;
	if (parse->args[1])
        set_export(env, parse->args);
	else
	{
		while (env)
		{
            if (!env->separator)
		        printf("declare -x %s\n", env->key);
            else if (!env->content)
		        printf("declare -x %s%s\n", env->key, env->separator);
            else
		        printf("declare -x %s%s%s\n", env->key, env->separator, env->content);
			env = env->next;
		}
	}
}