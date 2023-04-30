/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:29:05 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/30 17:03:18 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		wstatus;

	wstatus = 0;
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
		if (built_in_cmd(line) != 0)
			wstatus = pipex(line, envp);
		free (line);
	}
	// write_history(".my_history");
	exit(wstatus);
}
