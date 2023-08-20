/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:26:04 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/20 16:17:18 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_chdir(char **cmd, DIR *dir)
{
	struct dirent	*dp;

	dp = readdir(dir);
	while (dp != NULL)
	{
		if (ft_strcmp(cmd[1], dp->d_name) == 0)
		{
			ft_dprintf(2, "bash: cd: %s: Not a directory\n", cmd[1]);
			break ;
		}
		dp = readdir(dir);
	}
	if (!dp)
		ft_dprintf(2, "bash: cd: %s: No such file or directory\n", cmd[1]);
}

static void	update_oldpwd(char *oldpwd, t_list *env_head)
{
	t_list	*tmp;
	char	*old;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (ft_strcmp("OLDPWD", tmp->key) == 0)
		{
			old = tmp->value;
			tmp->value = ft_strdup(oldpwd);
			if (tmp->value == NULL)
				fatal_error("strdup");
			free(old);
			break ;
		}
		tmp = tmp->next;
	}
}

static char	*find_home_dir(t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (ft_strcmp(tmp->key, "HOME") == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("/Users");
}

int	ft_cd(char **cmd, char *cwd, t_list *env_head)
{
	DIR		*dir;
	char	*oldpwd;

	oldpwd = getcwd(cwd, 512);
	if (!cmd[1])
		chdir(find_home_dir(env_head));
	else if (chdir(cmd[1]) == -1)
	{
		dir = opendir(getcwd(cwd, 512));
		if (dir == NULL)
			ft_dprintf(2, "bash: cd: %s: No such file or directory\n", cmd[1]);
		else
			ft_chdir(cmd, dir);
		free(dir->__dd_buf);
		free(dir);
		return (1);
	}
	update_oldpwd(oldpwd, env_head);
	return (0);
}
