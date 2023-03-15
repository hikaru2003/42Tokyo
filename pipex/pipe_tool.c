/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:07:34 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 17:57:39 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int i, int argc, char *argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (is_cmd(argv, envp) == -1)
		return ;
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		perror("zsh: fork failed");
		exit(1);
	}
	if (pid == 0 && i == argc - 2)
		last_chile(argv, pipefd, envp);
	else if (pid == 0)
		do_child(argv, pipefd, envp);
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
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
