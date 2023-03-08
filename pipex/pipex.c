// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
// /*   Updated: 2023/03/08 20:02:01 by hmorisak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipex.h"

// int	get_file(char *file, int status)
// {
// 	int	fd;

// 	if (status == STDIN)
// 	{
// 		fd = open(file, O_RDONLY);
// 		if (fd == -1)
// 		{
// 			ft_printf("zsh: %s: %s\n", strerror(errno), file);
// 			return (-1);
// 		}
// 	}
// 	if (status == STDOUT)
// 		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
// 	return (fd);
// }

// int	is_cmd(char *argv, char **envp)
// {
// 	char	**cmd;
// 	char	**path;
// 	char	*filepath;

// 	cmd = ft_split(argv, ' ');
// 	path = get_path(envp);
// 	filepath = check_path(cmd, path);
// 	if (ft_strncmp(argv, "./", 2) == 0)
// 		return (0);
// 	else if (filepath == NULL)
// 	{
// 		write(STDERR, "zsh: command not found: ", 24);
// 		write(STDERR, cmd[0], ft_strlen(cmd[0]));
// 		write(STDERR, "\n", 1);
// 		return (-1);
// 	}
// 	return (0);
// }

// void	pipex(int i, int argc, char *argv, char **envp)
// {
// 	pid_t	pid;
// 	int		pipefd[2];

// 	if (is_cmd(argv, envp) == -1)
// 		return ;
// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("zsh: fork failed");
// 		exit(1);
// 	}
// 	if (pid == 0 && i == argc - 2)
// 		last_chile(argv, pipefd, envp);
// 	else if (pid == 0)
// 		do_child(argv, pipefd, envp);
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

// 	if (argc == 5)
// 	{
// 		infile = get_file(argv[1], STDIN);
// 		outfile = get_file(argv[argc - 1], STDOUT);
// 		dup2(infile, STDIN);
// 		dup2(outfile, STDOUT);
// 		if (infile != -1)
// 			pipex(2, argc, argv[2], envp);
// 		pipex(3, argc, argv[3], envp);
// 		wait(NULL);
// 		wait(NULL);
// 	}
// 	else
// 		ft_printf("Invalid number of argments.\n");
// 	return (1);
// }
