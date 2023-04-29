/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:56:38 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 21:24:13 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	**get_path(char *cmd, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
	{
		write(2, "bash: ", 6);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		perror("");
		return (NULL);
	}
	return (ft_split(envp[i] + 5, ':'));
}

char	*check_path(char **cmd, char **path)
{
	char	*path_slash;
	char	*filepath;
	int		i;

	if (access(cmd[0], X_OK) == 0)
		return (ft_strjoin(cmd[0], ""));
	i = 0;
	while (path[i])
	{
		path_slash = ft_strjoin(path[i], "/");
		filepath = ft_strjoin(path_slash, cmd[0]);
		char_single_free(&path_slash);
		if (access(filepath, X_OK) == 0)
			return (filepath);
		char_single_free(&filepath);
		i++;
	}
	return (NULL);
}

void	exec(char *line, char **envp)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	cmd = ft_split(line, ' '); //\t, \nもtokenizerで対応する
	path = get_path(cmd[0], envp);
	filepath = check_path(cmd, path);
	char_double_free(path);
	if (execve(filepath, cmd, envp) == -1)
	{
		perror("execve error");
		exit(127);
	}
}

int	is_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		return (-1);
	filepath = check_path(cmd, path);
	char_double_free(path);
	if (filepath == NULL || all_space(argv) == 0)
	{
		char_single_free(&filepath);
		write(STDERR, "zsh: command not found: ", 24);
		if (all_space(argv) == 0)
			write(STDERR, argv, ft_strlen(argv));
		else
			write(STDERR, cmd[0], ft_strlen(cmd[0]));
		write(STDERR, "\n", 1);
		char_double_free(cmd);
		return (-1);
	}
	char_double_free(cmd);
	char_single_free(&filepath);
	return (0);
}

int	all_space(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	pipex(char *line, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (*line == '\0' || is_cmd(line, envp) == -1) //enterのみの時に、command not foundにしたくないから
		return ;
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		perror("bash: fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		// dup2(pipefd[1], 1);	とりあえず、コマンドは一回のみ
		close(pipefd[1]);
		exec(line, envp);
	}
	else
	{
		close(pipefd[1]);
		// dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}
