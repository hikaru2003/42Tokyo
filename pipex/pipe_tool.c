/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:24:18 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/07 21:26:07 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (envp);
	return (ft_split(envp[i] + 5, ':'));
}

char	*check_path(char **cmd, char **path)
{
	char	*path_slash;
	char	*filepath;
	int		i;

	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	i = 0;
	while (path[i])
	{
		path_slash = ft_strjoin(path[i], "/");
		filepath = ft_strjoin(path_slash, cmd[0]);
		ft_free(&path_slash);
		if (access(filepath, X_OK) == 0)
			return (filepath);
		i++;
	}
	return (NULL);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	cmd = ft_split(argv, ' ');
	path = get_path(envp);
	filepath = check_path(cmd, path);
	execve(filepath, cmd, envp);
}

void	last_chile(char *argv, int *pipefd, char **envp)
{
	close(pipefd[0]);
	close(pipefd[1]);
	exec(argv, envp);
}

void	do_child(char *argv, int *pipefd, char **envp)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	exec(argv, envp);
}
