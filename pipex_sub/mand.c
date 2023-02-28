/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/28 19:17:03 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file(char *file, int status)
{
	int	fd;

	if (status == STDIN)
	{
		if (access(file, F_OK))
		{
			ft_printf("zsh: no such file or directory: %s\n", file);
			return (STDIN);
		}
		fd = open(file, O_RDONLY);
		if (fd == -1)
			return (STDIN);
	}
	if (status == STDOUT)
		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	return (fd);
}

char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
	{
		perror("no path");
		exit(1);
	}
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
	perror("bad path");
	exit(1);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	// printf("argv in exec = %s\n", argv);
	cmd = ft_split(argv, ' ');
	path = get_path(envp);
	filepath = check_path(cmd, path);
	printf("filepath = %s\n", filepath);
	execve(filepath, cmd, envp);
}

void	pipex(char *argv, char **envp, int *pipefd, int pid)
{
	if (pid == 0)
	{
		// printf("argv = %s\n", argv);
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	i;
	int	pipefd[2];
	int	*pid;
	int	tmp;

	pid = (int *)malloc(sizeof(int) * (argc - 2));
	if (!pid)
		return (1);
	i = 0;
	pipe(pipefd);
	while (i < argc - 2)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			perror("main");
			exit(1);
		}
		i++;
	}
	i = 1;
	while (i < argc - 1)
	{
		printf("pid[%d] == %d, cmd == %s\n", i - 1, pid[i - 1], argv[i]);
		pipex(argv[i], envp, pipefd, pid[i - 1]);
		printf("\n\n\npipex is returned\n\n\n");
		i++;
	}
	exec(argv[i], envp);
	printf("\n\n\nhere\n\n\n");
	i = 0;
	while (i < argc - 2)
	{
		tmp = waitpid(pid[i], NULL, 0);
		printf("tmp === %d\n", tmp);
		i++;
	}
	perror("execve");
	return (0);
}
