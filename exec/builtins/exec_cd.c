#include "../../inc/header.h"
// OLDPWD
// PWD
// unset PATH
// export var only one time
//echo
void    exec_cd(char *path)
{
	
    if (path == NULL || !ft_strncmp(path, "~", 2))
	{
        if(chdir(getenv("HOME")))
			printf("cd: HOME not set\n");
	}
	else
	{
		if (chdir(path))
			perror("cd: ");
	}
		//another case missing
}
