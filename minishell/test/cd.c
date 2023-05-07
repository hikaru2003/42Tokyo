/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:26:04 by hikaru            #+#    #+#             */
/*   Updated: 2023/05/07 22:26:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **cmd, char *cwd)
{
	DIR				*dir;
	struct dirent	*dp;

	if (!cmd[1])
		chdir(ft_strjoin("/Users/", getlogin()));
	else if (chdir(cmd[1]) == -1)
	{
		dir = opendir(getcwd(cwd, 512));
		if (dir == NULL)
			dprintf(2, "bash: cd: %s: No such file or directory\n", cmd[1]);
		else
		{
			dp = readdir(dir);
			while (dp != NULL)
			{
				if (ft_strcmp(cmd[1], dp->d_name) == 0)
				{
					dprintf(2, "bash: cd: %s: Not a directory\n", cmd[1]);
					break ;
				}
				dp = readdir(dir);
			}
			if (!dp)
				dprintf(2, "bash: cd: %s: No such file or directory\n", cmd[1]);
		}
		exit(1);
	}
	return (TRUE);
}
