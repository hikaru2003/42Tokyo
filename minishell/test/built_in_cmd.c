/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:57:28 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/03 21:35:33 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//unset
int	unset_path(char *path, t_list *env_head)
{
	t_list	*tmp;
	size_t	len;

	tmp = env_head->next;
	len = ft_strlen(path);
	while (tmp != env_head)
	{
		//pathとenvがpathの長さ分一致 && 次のenvの値が '=' である
		if (ft_strncmp(path, tmp->env, len) == 0 && tmp->env[len] == '=')
		{
			delete(env_head, tmp);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

int	print_env(t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		printf("%s\n", tmp->env);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	return (TRUE);
}

//builtin commandで実行できたときはTURE,実行できなかったときはFALSEを返す
int	built_in_cmd(char *line, t_list *env_head)
{
	char	**cmd;
	char	cwd[512];
	int		i;

	i = 1;
	if (*line == '\0')
		return (FALSE);
	cmd = ft_split(line, ' '); //tabも含める
	ft_memset(cwd, '\0', 512);
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
	{
		if (!cmd[i])
		{
			printf("\n");
			return (free_cmd(cmd));
		}
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
		return (free_cmd(cmd));
	}
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
	{
		if (!cmd[1])
			chdir(ft_strjoin("/Users/", getlogin()));
		else
			chdir(cmd[1]);
		return (free_cmd(cmd));
	}
	if (ft_strncmp(cmd[0], "pwd", 4) == 0)
	{
		printf("%s\n", getcwd(cwd, 512));
		return (free_cmd(cmd));
	}
	// if (ft_strncmp(cmd[0], "export", 7) == 0)
	// {
		
	// }
	if (ft_strncmp(cmd[0], "unset", 6) == 0)
	{
		if (cmd[1])
			unset_path(cmd[1], env_head);
		return (free_cmd(cmd));
	}
	if (ft_strncmp(cmd[0], "env", 4) == 0)
	{
		print_env(env_head);
		return (free_cmd(cmd));
	}
	if (ft_strncmp(cmd[0], "exit", 5) == 0)
	{
		exit(0);
	}
	free_cmd(cmd);
	return (FALSE); //builtin commandではなかった時
}
