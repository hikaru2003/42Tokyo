/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/08 23:05:53 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file(char *file, int status, int flag)
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
	if (status == STDOUT && access(file, F_OK) == 0 && access(file, W_OK) == -1)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), file);
		exit (1);
	}
	if (status == STDOUT && flag == 0)
		fd = open(file, (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	return (fd);
}

int	main(int argc, char *argv[], char **envp)
{
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		infile = get_file(argv[1], STDIN, 0);
		outfile = get_file(argv[argc - 1], STDOUT, 0);
		dup2(infile, STDIN);
		dup2(outfile, STDOUT);
		if (infile != -1)
			pipex(2, argc, argv[2], envp);
		pipex(3, argc, argv[3], envp);
		wait(NULL);
		wait(NULL);
	}
	else
		ft_printf("Invalid number of argments.\n");
	return (1);
}
