/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/18 21:10:02 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_get_file_error(char *err_msg, char *file)
{
	write(STDERR, "zsh: ", 5);
	write(STDERR, err_msg, ft_strlen(err_msg));
	write(STDERR, ": ", 2);
	write(STDERR, file, ft_strlen(file));
	write(STDERR, "\n", 1);
}

int	get_file(char *file, int status, int flag)
{
	int	fd;

	if (status == STDIN)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			write_get_file_error(strerror(errno), file);
			return (-1);
		}
	}
	if (status == STDOUT && access(file, F_OK) == 0 && access(file, W_OK) == -1)
	{
		write_get_file_error(strerror(errno), file);
		exit (1);
	}
	if (status == STDOUT && flag == 0)
		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	if (status == STDOUT && flag == 1)
		fd = open(file, (O_CREAT | O_WRONLY | O_APPEND), 0644);
	return (fd);
}

void	do_pipex(int i, int argc, char **argv, char **envp)
{
	while (i < argc - 1)
	{
		pipex(i, argc, argv[i], envp);
		i++;
	}
}

void	do_wait(int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		wait(NULL);
		i++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	i;
	int	flag;

	flag = 0;
	if (argc >= 5)
	{
		i = 2;
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		{
			flag = here_doc(argv, argv[2], ft_strlen(argv[2]));
			i = 3;
		}
		if (get_file(argv[1], STDIN, flag) == -1)
			i = 3;
		else
			dup2(get_file(argv[1], STDIN, flag), STDIN);
		dup2(get_file(argv[argc - 1], STDOUT, flag), STDOUT);
		do_pipex(i, argc, argv, envp);
		do_wait(argc);
		unlink(".tmp.txt");
	}
	else
		ft_printf("Invalid number of argments.\n");
	return (1);
}
