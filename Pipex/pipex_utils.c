/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-18 15:59:47 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-12-18 15:59:47 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(const char *name, char **envp)
{
	int		i;
	size_t	len;

	if (!name || !envp)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
		{
			return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**path;
	char	*directory;
	char	**split_cmd;

	i = -1;
	path = ft_split(ft_getenv("PATH", envp), ':');
	split_cmd = ft_split(cmd, ' ');
	while (path[++i])
	{
		directory = ft_strjoin(path[i], "/");
		exec = ft_strjoin(directory, split_cmd[0]);
		free(directory);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_array(path);
			ft_free_array(split_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_array(path);
	ft_free_array(split_cmd);
	return (cmd);
}
