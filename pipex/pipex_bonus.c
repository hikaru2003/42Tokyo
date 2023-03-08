/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/08 20:15:54 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file(char *file, int status)
{
	int	fd;

	if (status == STDIN)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			ft_printf("zsh: %s: %s\n", strerror(errno), file);
			return (-1);
		}
	}
	if (status >= 2 && access(file, W_OK) == -1)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), file);
		exit (1);
	}
	if (status == 2)
		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	if (status == 3)
		fd = open(file, (O_CREAT | O_WRONLY | O_APPEND), 0644);
	return (fd);
}

int	is_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*filepath;

	cmd = ft_split(argv, ' ');
	path = get_path(envp);
	filepath = check_path(cmd, path);
	if (filepath == NULL)
	{
		write(STDERR, "zsh: command not found: ", 24);
		write(STDERR, cmd[0], ft_strlen(cmd[0]));
		write(STDERR, "\n", 1);
		return (-1);
	}
	return (0);
}

void	pipex(int i, int argc, char *argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
	{
		perror("zsh: fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		if (i == argc - 2)
			last_chile(argv, pipefd, envp);
		else
			do_child(argv, pipefd, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
	}
}

int	here_doc(char **argv, char *limiter, int lmtlen)
{
	int		fd;
	int		line_len;
	char	*buf;
	char	*line;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return (INT_MAX);
	fd = open(".tmp.txt", (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	line = (char *)malloc(1);
	while (1)
	{
		ft_printf("> ");
		buf = get_next_line(STDIN);
		if (!buf)
			break ;
		line_len = ft_strlen(buf);
		if ((lmtlen == line_len - 1) && !ft_strncmp(buf, limiter, lmtlen))
			break ;
		line = gnl_strjoin(line, buf);
	}
	write(fd, line, ft_strlen(line));
	argv[1] = ".tmp.txt";
	return (3);
}

int	main(int argc, char *argv[], char **envp)
{
	int	i;

	if (argc >= 5)
	{
		i = 2;
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			i = here_doc(argv, argv[2], ft_strlen(argv[2]));
		if (get_file(argv[1], STDIN) == -1)
			i = 3;
		else
			dup2(get_file(argv[1], STDIN), STDIN);
		dup2(get_file(argv[argc - 1], i), STDOUT);
		while (i < argc - 1)
		{
			pipex(i, argc, argv[i], envp);
			i++;
		}
		i = 0;
		while (i < argc - 3)
		{
			wait(NULL);
			i++;
		}
	}
	else
		ft_printf("Invalid number of argments.\n");
	return (1);
}
