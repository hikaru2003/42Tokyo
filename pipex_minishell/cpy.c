// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipex.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
// /*   Updated: 2023/03/01 18:53:37 by hmorisak         ###   ########.fr       */
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
// 		if (i == argc - 2)
// 			last_chile(argv, pipefd, envp);
// 		else
// 			do_child(argv, pipefd, envp);
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

// 	if (argc == 5)
// 	{
// 		infile = get_file(argv[1], STDIN);
// 		outfile = get_file(argv[argc - 1], STDOUT);
// 		dup2(infile, STDIN);
// 		dup2(outfile, STDOUT);
// 		pipex(2, argc, argv[2], envp);
// 		pipex(3, argc, argv[3], envp);
// 		wait(NULL);
// 		wait(NULL);
// 	}
// 	else
// 		ft_printf("Invalid number of argments.\n");
// 	return (1);
// }
