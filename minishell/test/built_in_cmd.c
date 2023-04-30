/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:57:28 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/30 17:27:06 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_in_cmd(char *line)
{
	char	**cmd;

	if (*line == '\0')
		return (-1);
	cmd = ft_split(line, ' ');
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
	{
		if (!cmd[1])
			return (chdir(ft_strjoin("/Users/", getlogin()))); //builtin commandで実行できたときは0,実行できなかったときは-1を返す
		else
			return (chdir(cmd[1]));
	}
	return (-1); //builtin commandではなかった時
}
