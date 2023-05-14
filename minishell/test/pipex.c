/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:56:38 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/14 11:25:50 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char *cmd, t_list *env_head)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = env_head->next;
	while (tmp != env_head && ft_strncmp(tmp->env, "PATH=", 5))
		tmp = tmp->next;
	if (tmp == env_head)
	{
		write(2, "bash: ", 6);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": ", 2);
		perror("");
		return (NULL);
	}
	return (ft_split(&tmp->env[5], ':'));
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

char	**list_to_array(t_list *env_head)
{
	int		i;
	t_list	*tmp;
	char	**array;

	i = 0;
	tmp = env_head->next;
	array = (char **)malloc(sizeof(char *) * (env_head->count + 1));
	if (!array)
		return (NULL);
	while (i < env_head->count && tmp != env_head)
	{
		array[i] = ft_strdup(tmp->env);
		if (!array[i])
			return (free_array(array));
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}

void	exec(char *line, t_list *env_head)
{
	char		**cmd;
	char		**path;
	char		*filepath;
	char	**env_array;

	cmd = ft_split(line, ' ');
	path = get_path(cmd[0], env_head);
	filepath = check_path(cmd, path);
	char_double_free(path);
	env_array = list_to_array(env_head);
	if (execve(filepath, cmd, env_array) == -1)
	{
		perror("execve error");
		exit(127);
	}
}

int	is_cmd(char *argv, t_list *env_head)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], env_head);
	if (!path)
		return (-1);
	filepath = check_path(cmd, path);
	char_double_free(path);
	if (filepath == NULL || all_space(argv) == 0)
	{
		char_single_free(&filepath);
		write(STDERR, "bash: command not found: ", 24);
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

int	pipex(char *line, t_list *env_head)
{
	pid_t	pid;
	int		pipefd[2];
	int		wstatus;

	//enterのみの時に、command not foundにしたくないから
	if (*line == '\0' || is_cmd(line, env_head) == -1)
		return (-1);
	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		perror("bash: fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		close(pipefd[READ]);
		dup2(pipefd[WRITE], STDOUT);
		close(pipefd[WRITE]);
		exec(line, env_head);
	}
	else
	{
		close(pipefd[WRITE]);
		dup2(pipefd[READ], STDIN);
		close(pipefd[READ]);
		wait(&wstatus);
	}
	return (wstatus);
}
