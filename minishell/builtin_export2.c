/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:53 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/14 21:04:59 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reset_flag(t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (ft_strcmp(tmp->key, "_") != 0)
			tmp->sort_flag = 0;
		tmp = tmp->next;
	}
	return (0);
}

static int	print_export(t_list *env_head, t_node *node)
{
	t_list	*sort;
	t_list	*min;
	int		i;

	sort = env_head->next;
	min = sort;
	i = 0;
	while (i < env_head->count)
	{
		sort = env_head->next;
		while (sort->sort_flag == 1 && sort != env_head)
			sort = sort->next;
		if (sort == env_head)
			return (reset_flag(env_head));
		min = sort;
		min = find_min(env_head, sort, min);
		min->sort_flag = 1;
		if (ft_strcmp(min->value, "\0") == 0)
			ft_dprintf(node->outpipe[1], "declare -x %s\n", min->key);
		else
			ft_dprintf(node->outpipe[1], "declare -x %s=\"%s\"\n", \
				min->key, min->value);
		i++;
	}
	return (reset_flag(env_head));
}

static int	check_exist(char *cmd, t_list *env_head)
{
	t_list	*list;

	list = env_head->next;
	while (list != env_head)
	{
		if (ft_strcmp(list->key, cmd) == 0)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

void	non_equal(char **cmd, t_list *env_head, int i, int j)
{
	t_list	*list;

	while (cmd[i][j])
	{
		if (is_alpha_num_under(cmd[i][j]))
			j++;
		else
		{
			ft_dprintf(STDOUT_FILENO, "%s", ERROR_PREFIX);
			ft_dprintf(1, "export: `%s': not a valid identifier\n", cmd[i]);
			g_var.g_last_status = 1;
			return ;
		}
	}
	if (check_exist(cmd[i], env_head) == TRUE)
		return ;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		fatal_error("malloc");
	list->key = ft_strdup(cmd[i]);
	list->value = ft_strdup("\0");
	if (!list->key || !list->value)
		fatal_error("strdup");
	list->sort_flag = 0;
	insert(env_head, list);
}

int	ft_export(char **cmd, t_list *env_head, t_node *node)
{
	int	i;

	i = 1;
	if (!cmd[1])
		return (print_export(env_head, node));
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "_") == 0)
			continue ;
		if (is_alpha_under(cmd[i][0]))
			do_export(cmd, env_head, i);
		else
		{
			ft_dprintf(STDOUT_FILENO, "%s", ERROR_PREFIX);
			ft_dprintf(1, "export: `%s': not a valid identifier\n", cmd[i]);
			g_var.g_last_status = 1;
		}
		i++;
	}
	return (g_var.g_last_status);
}
