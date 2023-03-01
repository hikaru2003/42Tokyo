// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stdin_out.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
// /*   Updated: 2023/03/01 18:03:18 by hmorisak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// int	get_file(char *file, int status)
// {
// 	int	fd;

// 	if (status == STDIN)
// 	{
// 		if (access(file, F_OK))
// 		{
// 			ft_printf("zsh: no such file or directory: %s\n", file);
// 			return (STDIN);
// 		}
// 		fd = open(file, O_RDONLY);
// 		if (fd == -1)
// 			return (STDIN);
// 	}
// 	if (status == STDOUT)
// 		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
// 	return (fd);
// }

// char	**get_path(char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
// 		i++;
// 	if (!envp[i])
// 	{
// 		perror("no path");
// 		exit(1);
// 	}
// 	return (ft_split(envp[i] + 5, ':'));
// }

// char	*check_path(char **cmd, char **path)
// {
// 	char	*path_slash;
// 	char	*filepath;
// 	int		i;

// 	i = 0;
// 	while (path[i])
// 	{
// 		path_slash = ft_strjoin(path[i], "/");
// 		filepath = ft_strjoin(path_slash, cmd[0]);
// 		ft_free(&path_slash);
// 		if (access(filepath, X_OK) == 0)
// 			return (filepath);
// 		i++;
// 	}
// 	perror("bad path");
// 	exit(1);
// }

// void	exec(char *argv, char **envp)
// {
// 	char	**cmd;
// 	char	**path;
// 	char	*filepath;

// 	cmd = ft_split(argv, ' ');
// 	path = get_path(envp);
// 	filepath = check_path(cmd, path);
// 	execve(filepath, cmd, envp);
// }

// void	pipex(int i, int argc, char *argv, char **envp)
// {
// 	pid_t	pid;
// 	int		pipefd[2];

// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("main");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (i == argc - 1)
// 		{
// 			close(pipefd[0]);
// 			close(pipefd[1]);
// 			exec(argv, envp);
// 		}
// 		else
// 		{
// 			close(pipefd[0]);
// 			dup2(pipefd[1], 1);
// 			close(pipefd[1]);
// 			exec(argv, envp);
// 		}
// 	}
// 	else
// 	{
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		close(pipefd[0]);
// 	}
// }

// int	main(int argc, char *argv[], char **envp)
// {
// 	int	infile;
// 	int	outfile;
// 	int	i;

// 	// infile = get_file(argv[1], STDIN);
// 	// outfile = get_file(argv[argc - 1], STDOUT);
// 	// dup2(infile, STDIN);
// 	// dup2(outfile, STDOUT);
// 	// close(infile); 必要か？
// 	// close(outfile);
// 	i = 1;
// 	while (i < argc)
// 	{
// 		pipex(i, argc, argv[i], envp);
// 		i++;
// 	}
// 	i = 0;
// 	while(i < argc - 1)
// 	{
// 		wait(NULL);
// 		i++;
// 	}
// 	return (0);
// }
