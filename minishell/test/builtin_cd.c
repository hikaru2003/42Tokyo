/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:26:04 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/04 12:37:40 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_chdir(char **cmd, DIR *dir)
{
	struct dirent	*dp;

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

void	update_oldpwd(char *oldpwd, t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (ft_strcmp("OLDPWD", tmp->key) == 0)
		{
			tmp->value = ft_strdup(oldpwd);
			break ;
		}
		tmp = tmp->next;
	}
}

int	ft_cd(char **cmd, char *cwd, t_list *env_head)
{
	DIR		*dir;
	char	*oldpwd;

	oldpwd = getcwd(cwd, 512);
	if (!cmd[1])
		chdir(ft_strjoin("/Users/", getlogin()));
	else if (chdir(cmd[1]) == -1)
	{
		dir = opendir(getcwd(cwd, 512));
		if (dir == NULL)
			dprintf(2, "bash: cd: %s: No such file or directory\n", cmd[1]);
		else
			ft_chdir(cmd, dir);
		return (1);
	}
	update_oldpwd(oldpwd, env_head);
	return (0);
}
