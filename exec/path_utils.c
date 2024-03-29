/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:59:10 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/09/03 00:59:13 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

char	**find_path(char **envp)
{
	int		i;
	char	**env_path;
	char	**paths;

	i = find_path_env(envp, "PATH=");
	if (i != -1)
	{
		env_path = ft_split(envp[i], '=');
		paths = ft_split(env_path[1], ':');
		free_array(env_path);
		return (paths);
	}
	return (NULL);
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
	return (-1);
}

char	*search(char **envp, char *cmd, int i)
{
	char	**paths;
	char	*x;
	char	*x2;

	paths = find_path(envp);
	if (paths)
	{
		while (paths[i])
		{
			x2 = join_env(paths[i], "/");
			x = join_env(x2, cmd);
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
	}
	if (access(cmd, F_OK) == 0)
		return (cmd);
	return (NULL);
}
