#include "../inc/header.h"


char **ft_get_env(env_list *env, char **envp)
{
	int i;

	env->envp = malloc(sizeof(char *) * (ft_count_elems(envp) + 1));
	i = 0;
	while(i < ft_count_elems(envp))
	{
		env->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	env->envp[i + 1] = NULL;
	return (env->envp);
}