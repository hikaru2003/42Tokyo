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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //pid_t wait(int *status_ptr);, pid_t waitpid(pid_t pid, int *status_ptr, int options);
#include <sys/types.h> //pid_t fork(void);
#include <fcntl.h>

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
// 	argv[2] = "I"m hikaru";
// 	argv[3] = NULL;
// 	execve("/bin/echo", argv, environ);

// 	perror("execve");
// 	return (-1);
// }


// int	main(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid > 0)
// 		printf("%d\n", pid);
// 	else if (pid == 0)
// 		printf("%d\n", pid);
// 	return (0);
// }

// #define BUFF_SIZE 1024

// int main(int argc, char **argv)
// {
//   int         pipefd[2];
//   int         p_id;
//   int         status;
//   FILE        *fp;
//   char        buff[BUFF_SIZE];

//   if (argc != 2) {
//     fprintf(stderr, "main : 実行時引数の数が不当です\n");
//     exit(EXIT_FAILURE);
//   }

//   if (pipe(pipefd) == -1) {
//     perror("main ");
//     exit(EXIT_FAILURE);
//   }

//   if ((p_id = fork()) == -1) {
//     perror("main ");
//     exit(EXIT_FAILURE);
//   }

//   if (p_id == 0) {
//     /* 子プロセス */
//     /* 使用しないwrite側はクローズ */
//     close(pipefd[1]);
//     /* パイプから読み込む */
//     while (read(pipefd[0], &buff, BUFF_SIZE) > 0) {
//       fputs(buff, stdout);
//     }
//     close(pipefd[0]);
//   }
//   else {
//     /* 親プロセス */
//     /* 使用しないread側はクローズ */
//     close(pipefd[0]);

//     if ((fp = fopen(*(argv + 1), "r")) != NULL) {
//       while(fgets(buff, BUFF_SIZE, fp) != NULL) {
//         /* パイプに書き込む */
//         write(pipefd[1], buff, strlen(buff) + 1);
//       }

//       fclose(fp);
//     }
//     else {
//       perror("親プロセス ");
//     }

//     close(pipefd[1]);
//     wait(&status);
//   }

//   return EXIT_SUCCESS;
// }

// int	main(void)
// {
// 	int pipefd[2];

// 	pipe(pipefd);
// 	printf("%d, %d\n", pipefd[0], pipefd[1]);


// 	return (0);
// }