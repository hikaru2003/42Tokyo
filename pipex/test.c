/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:09:40 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/23 21:04:29 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h> //pid_t wait(int *status_ptr);, pid_t waitpid(pid_t pid, int *status_ptr, int options);
// #include <sys/types.h> //pid_t fork(void);
// #include <fcntl.h>

// int	main(void)
// {
// 	int	fd;
// 	char	*argv[4];
// 	extern char	**environ;

// 	if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
// 	{
// 		perror("open");
// 		return (-1);
// 	}
// 	if (dup2(fd, 1) < 0)
// 	{
// 		perror("dup2");
// 		close(fd);
// 		return (-1);
// 	}
// 	close(fd);

// 	argv[0] = "echo";
// 	argv[1] = "Hello World!\n";
// 	argv[2] = "I'm hikaru";
// 	argv[3] = NULL;
// 	execve("/bin/echo", argv, environ);

// 	perror("execve");
// 	return (-1);
// }

