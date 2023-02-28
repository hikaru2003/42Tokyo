// #include <libc.h>

// int	main(void)
// {
// 	int i = 1;
// 	int	pipefd[2];
// 	pid_t	pid[3];

// 	pipe(pipefd);
// 	pid[0] = fork();
// 	while (i < 3)
// 	{
// 		if (pid[i - 1] != 0)
// 		// printf("here\n");
// 			pid[i] = fork();
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("%d\n", pid[i]);
// 		i++;
// 	}

// 	// i = 0;
// 	// while(i < 3)
// 	// {
// 	// 	// if (pid[i] == pid[0] + i)
// 	// 		printf("%d, %d\n", i, pid[i]);
// 	// 	i++;
// 	// }
// 	return 0;
// }
