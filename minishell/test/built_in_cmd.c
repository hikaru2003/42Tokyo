/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:57:28 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/30 21:04:06 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_cmd(char *line)
{
	char	**cmd;
	char	cwd[512];
	int		i;

	i = 1;
	if (*line == '\0')
		return (-1);
	cmd = ft_split(line, ' '); //tabも含める
	ft_memset(cwd, '\0', 512);
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
	{
		if (ft_strncmp(cmd[1], "-n", 3) == 0)
			i = 2;
		while (cmd[i])
		{
			ft_putstr_fd(cmd[i], 1);
			if (cmd[++i])
				ft_putstr_fd(" ", 1);
		}
		if (ft_strncmp(cmd[1], "-n", 3) != 0)
			ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
	{
		if (!cmd[1])
			return (chdir(ft_strjoin("/Users/", getlogin()))); //builtin commandで実行できたときは0,実行できなかったときは-1を返す
		else
			return (chdir(cmd[1]));
	}
	if (ft_strncmp(cmd[0], "pwd", 4) == 0)
	{
		printf("%s\n", getcwd(cwd, 512));
		return (0);
	}
	// if (ft_strncmp(cmd[0], "export", 7) == 0)
	// {
		
	// }
	// if (ft_strncmp(cmd[0], "unset", 6) == 0)
	// {

	// }
	if (ft_strncmp(cmd[0], "env", 4) == 0)
	{
		i = 0;
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (0);
	}
	// if (ft_strncmp(cmd[0], "exit", 5) == 0)
	// {
		
	// }
	return (-1); //builtin commandではなかった時
}
