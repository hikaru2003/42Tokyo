/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:27:18 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/26 21:34:06 by hmorisak         ###   ########.fr       */
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
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*check_path(char **cmd, char **path)
{
	char	*path_slash;
	char	*filepath;
	int		i;

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

void	exec(char *argv, char **path)
{
	char	**cmd;
	char	*filepath;

	cmd = ft_split(argv, ' ');
	filepath = check_path(cmd, path);
	if (filepath)
		execve(cmd[0], cmd, environ);
}

void	pipex(int argc, char **argv, char **path)
{
	pid_t	pid;
	int		pipefd[2];
	int		i;

	i = 1;
	// while (i < argc)
	// {
		if (pipe(pipefd) == -1)
		{
			perror("main");
			exit(-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("main");
			exit(-1);
		}
		if (pid > 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			waitpid(pid, NULL, 0);
			// close(pipefd[0]);
		}
		if (pid == 0)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
			exec(argv[i], path);
		}
	// }
}

int	main(int argc, char *argv[])
{
	char	**path;

	path = get_path(environ);
	pipex(argc, argv, path);
	return (0);
}
