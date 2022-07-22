  #include "../inc/header.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] && s22[i] && s11[i] == s22[i])
		{
			i++;
			continue ;
		}
		return (s11[i] - s22[i]);
	}
	return (0);
}

char	**find_path(char **envp)
{
	int		i;
	char	**env_path;
	char	**paths;

	i = find_path_env(envp, "PATH=");
	env_path = ft_split(envp[i], '=');
	paths = ft_split(env_path[1], ':');
	free_array(env_path);
	return (paths);
}

int	find_path_env(char **envp, char *path)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], path, 5))
			return (i);
		i++;
	}
	return (0);
}

char	*search(char **envp, char *cmd)
{
	int		i;
	char	**paths;
	char	*x;
	char	*x2;

	i = 0;
	paths = find_path(envp);
	while (paths[i])
	{
		x2 = ft_strjoin(paths[i], "/");
		x = ft_strjoin(x2, cmd);
		free(x2);
		if (access(x, F_OK) == 0)
		{
			free_array(paths);
			return (x);
		}
		free(x);
		i++;
	}
	free_array(paths);
	if (access(cmd, F_OK) == 0)
		return (cmd);
	return (NULL);
}
