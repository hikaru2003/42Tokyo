/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/26 20:52:20 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// char	**get_path(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
// 		i++;
// 	if (!envp[i])
// 		return (NULL);
// 	return (ft_split(envp[i] + 5, ':'));
// }

// char	*check_path(char *argv, char **path)
// {
// 	char	*path_slash;
// 	char	*filepath;
// 	char	**only_cmd;
// 	int		i;

// 	i = 0;
// 	only_cmd = ft_split(argv, ' ');
// 	while (path[i])
// 	{
// 		path_slash = ft_strjoin(path[i], "/");
// 		filepath = ft_strjoin(path_slash, only_cmd[0]);
// 		ft_free(&path_slash);
// 		if (access(filepath, X_OK) == 0)
// 			return (filepath);
// 		i++;
// 	}
// 	return (NULL);
// }

// void	pipex(int i, char *argv[])
// {
// 	pid_t	pid;
// 	int		pipe_fd[2];

// 	pipe(pipe_fd);
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(-1);
// 	}
// 	if (pid == 0)
// 	{
// 		close(pipe_fd[0]);
// 		dup2(pipe_fd[1], 1);
// 		close(pipe_fd[1]);
// 		pipex(i + 1, argv);
// 	}
// 	else
// 	{
// 		close(pipe_fd[1]);
// 		dup2(pipe_fd[0], 0);
// 		close(pipe_fd[0]);

// 	}
// }

// // int	count_cmd(char *argv[])  bonus_part
// // {
// // 	int	i;

// // 	i = 0;
// // 	while (argv[i])
// // 		i++;
// // 	return (i);
// // }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	char	**path;
// 	char	*cmd;
// 	// int		cmd_num;  bonus

// 	path = get_path(envp);
// 	// while (*path)
// 	// {
// 	// 	printf("%s\n", *path);
// 	// 	path++;
// 	// }
// 	if ((cmd = check_path(argv[2], path)) == NULL)
// 		return (-1);
// 	// printf("%s\n", cmd);

// 	// cmd_num = count_cmd(&argv[1]);  bonus
// 	pipex(0, &argv[1]);

// 	// int	fd;
// 	// extern char	**environ;

// 	// if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
// 	// {
// 	// 	perror("open");
// 	// 	return (-1);
// 	// }
// 	// if (dup2(fd, 0) < 0)
// 	// {
// 	// 	perror("dup2");
// 	// 	close(fd);
// 	// 	return (-1);
// 	// }
// 	// close(fd);

// 	pipex(0, argv);
// 	execve(cmd, &argv[2], environ);

// 	perror("execve");

// 	return (0);
// }
