#include "../../inc/header.h"

void    exec_cd(char *path, env_list *env)
{
	
    if (path == NULL || !ft_strncmp(path, "~", 2))
	{
		if (search_env(&env, "HOME"))
		{
        	if(chdir(getenv("HOME")))
				printf("cd: HOME not set\n");
		}
	}
	else
	{
		if (chdir(path))
			perror("cd: ");
	}
		//another case missing
}
