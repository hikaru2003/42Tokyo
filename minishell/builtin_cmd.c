/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:57:28 by hmorisak          #+#    #+#             */
/*   Updated: 2023/08/15 18:08:50 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert(t_list *head, t_list *list)
{
	head->prev->next = list;
	list->prev = head->prev;
	head->prev = list;
	list->next = head;
	head->count++;
}

void	delete(t_list *head, t_list *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
	free(list->key);
	free(list->value);
	free(list);
	head->count--;
}

int	is_builtin(char **cmd)
{
	if (cmd[0] == NULL)
		return (FALSE);
	if (ft_strcmp(cmd[0], "echo") != 0 && ft_strcmp(cmd[0], "cd") != 0
		&& ft_strcmp(cmd[0], "pwd") != 0 && ft_strcmp(cmd[0], "export") != 0
		&& ft_strcmp(cmd[0], "unset") != 0 && ft_strcmp(cmd[0], "env") != 0
		&& ft_strcmp(cmd[0], "exit") != 0)
		return (FALSE);
	return (TRUE);
}

int	built_in_cmd(char **cmd, t_list *env_head, t_node *node)
{
	char	cwd[512];

	ft_memset(cwd, '\0', 512);
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_cd(cmd, cwd, env_head));
	if (ft_strcmp(cmd[0], "exit") == 0)
		return (ft_exit(cmd));
	if (ft_strcmp(cmd[0], "echo") == 0)
		return (ft_echo(cmd, node));
	if (ft_strcmp(cmd[0], "pwd") == 0)
		return (ft_pwd(cwd, node));
	if (ft_strcmp(cmd[0], "unset") == 0)
		return (ft_unset(cmd, env_head));
	if (ft_strcmp(cmd[0], "env") == 0)
		return (ft_env(env_head, node));
	if (ft_strcmp(cmd[0], "export") == 0)
		return (ft_export(cmd, env_head, node));
	return (0);
}
