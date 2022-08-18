#include "../../inc/header.h"

int     check_export_key(char *key)
{
    int i;

    i = 1;
    if (ft_isalpha(key[0]))
    {
        while(key[i])
        {
            if (!ft_isalnum(key[i]))
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
    // char    **tmp = NULL;
    int i;
    env_list *tmp;
    i = 1;
    while(args[i])
    {
        if (check_export_key(args[i]))
        {
            // if (!ft_strchr(*args, '='))
            // {
            //     tmp = ft_split(*args, '=');
            //     if (!tmp[1])
            //         env_add_back(&env, new_env(tmp[0], tmp[1], "="));
            //     else
            //         env_add_back(&env, new_env(tmp[0], NULL, "="));
            // }
            // else
            tmp = new_env(args[i], "=", "=");
                env_add_back(&env, tmp);
                printf("%s\n", env_last(env)->key);
                                printf("%s\n", env->key);

                
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

void    print_export(env_list **env)
{
	env_list *list;

	list = *env;
	while (!list)
	{
        if (!list->separator)
		    printf("declare -x %s\n", list->key);
        else if (!list->content)
		    printf("declare -x %s%s\n", list->key, list->separator);
        else
		    printf("declare -x %s%s%s\n", list->key, list->separator, list->content);
		list = list->next;
	}
}

void exec_export(t_parser *parse, env_list **envp)
{
	env_list	*env;
    env_list	*tmp;

	env = *envp;
	if (parse->args[1])
	{
        tmp = new_env(parse->args[1], parse->args[1], parse->args[1]);
            env_add_back(&env, tmp);
    }
	else
	{
		while (env)
		{
			printf("declare -x %s%s%s\n", env->key, env->separator, env->content);
			env = env->next;
		}
	}
}