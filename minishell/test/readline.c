/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:29:05 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/29 20:26:27 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	rl_outstream = stderr;
	// using_history();
	// read_history(".my_history");
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		pipex(line, envp);
		wait(NULL);
		free (line);
	}
	// write_history(".my_history");
	exit(0);
}