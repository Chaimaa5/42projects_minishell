#include "../../inc/header.h"

char	*pwd()
{
	char buf[250];
	char *buff;

	buff = buf;
    getcwd(buf, sizeof(buf));
	buff =ft_strdup(buf);
	return (buff);
}

void    exec_cd(char *path, t_env_list *env)
{
	char *old_pwd;

	old_pwd = pwd();
    if (path == NULL || !ft_strncmp(path, "~", 2))
	{
		if (search_env(&env, "HOME"))
		{
			chdir(get_env(&env, "HOME"));
			replace_value(&env, "PWD", pwd());
			replace_value(&env, "OLDPWD", old_pwd);
		}
		else
		{
			printf("cd: HOME not set\n");
			exit_code = 1;
		}
	}
	else
	{
		if (chdir(path))
		{
			perror("cd: ");
			exit_code = 1;
		}
		else
		{
			replace_value(&env, "PWD", pwd());
			replace_value(&env, "OLDPWD", old_pwd);
		}

	}
}

