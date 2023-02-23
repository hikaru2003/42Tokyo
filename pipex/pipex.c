/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:56 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/23 21:06:39 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

char	*check_path(char *argv, char **path)
{
	char	*path_slash;
	char	*filepath;
	int		i;

	i = 0;
	while (path[i])
	{
		path_slash = ft_strjoin(path[i], "/");
		filepath = ft_strjoin(path_slash, argv);
		ft_free(&path_slash);
		if (access(filepath, X_OK) == 0)
			return (filepath);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	char	*cmd;

	path = get_path(envp);
	// while (*path)
	// {
	// 	printf("%s\n", *path);
	// 	path++;
	// }
	if ((cmd = check_path(argv[1], path)) == NULL)
		return (-1);
	// printf("%s\n", cmd);

	int	fd;
	extern char	**environ;

	if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
	{
		perror("open");
		return (-1);
	}
	if (dup2(fd, 1) < 0)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);

	execve(cmd, &argv[1], environ);

	perror("execve");

	return (0);
}
