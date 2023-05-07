// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/26 23:29:05 by hikaru            #+#    #+#             */
// /*   Updated: 2023/05/04 17:45:28 by hikaru           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// int	main(int argc, char **argv)
// {
// 	char	*line;
// 	int		wstatus;
// 	t_list	*env_head;

// 	wstatus = 0;
// 	rl_outstream = stderr;
// 	env_head = env_to_list();
// 	// using_history();
// 	// read_history(".my_history");
// 	while (1)
// 	{
// 		line = readline("minishell$ ");
// 		if (!line)
// 			break ;
// 		if (*line)
// 			add_history(line);
// 		// if (built_in_cmd(line, env_head) != TRUE)
// 			wstatus = pipex(line, env_head); //一旦builtinなしでやる
// 		free (line);
// 	}
// 	free_t_list(env_head);
// 	// write_history(".my_history");
// 	exit(wstatus);
// }

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q minishell");
// }
