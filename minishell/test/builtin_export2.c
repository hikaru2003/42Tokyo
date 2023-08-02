/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:53 by hikaru            #+#    #+#             */
/*   Updated: 2023/07/21 19:00:06 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_flag(t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (ft_strcmp(tmp->key, "_") != 0)
			tmp->sort_flag = 0;
		tmp = tmp->next;
	}
	return (TRUE);
}

t_list	*find_min(t_list *env_head, t_list *sort, t_list *min)
{
	while (sort != env_head)
	{
		if (sort->sort_flag == 0 && ft_strcmp(min->key, sort->key) > 0)
			min = sort;
		sort = sort->next;
	}
	return (min);
}

int	print_export(t_list *env_head)
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
		if (strcmp(min->value, "\0") == 0)
			dprintf(1, "declare -x %s\n", min->key);
		else
			dprintf(1, "declare -x %s=\"%s\"\n", min->key, min->value);
		i++;
	}
	return (reset_flag(env_head));
}

int	check_exist(char *cmd, t_list *env_head)
{
	t_list	*list;

	list = env_head->next;
	while (list != env_head)
	{
		if (strcmp(list->key, cmd) == 0)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

void	non_equal(char **cmd, t_list *env_head, int i)
{
	int		j;
	t_list	*list;

	j = 0;
	while (cmd[i][j])
	{
		if (('a' <= cmd[i][j] && cmd[i][j] <= 'z')
			|| ('A' <= cmd[i][j] && cmd[i][j] <= 'Z')
			|| cmd[i][j] == '_' || ('0' <= cmd[i][j] && cmd[i][j] <= '9'))
			j++;
		else
		{
			dprintf(1, "bash: export: `%s': not a valid identifier\n", cmd[i]);
			return ;
			// exit(1);
		}
	}
	if (check_exist(cmd[i], env_head) == TRUE)
		return ;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		exit(1);
	list->key = ft_strdup(cmd[i]);
	list->value = ft_strdup("\0");
	list->sort_flag = 0;
	insert(env_head, list);
}

int	ft_export(char **cmd, t_list *env_head)
{
	int		i;

	i = 1;
	if (!cmd[1])
		return (print_export(env_head));
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "_") == 0)
		{
			// exit(0);
			return (TRUE);
		}
		if (('a' <= cmd[i][0] && cmd[i][0] <= 'z')
			|| ('A' <= cmd[i][0] && cmd[i][0] <= 'Z') || cmd[i][0] == '_')
			do_export(cmd, env_head, i);
		else
		{
			dprintf(1, "bash: export: `%s': not a valid identifier\n", cmd[i]);
			// exit(1);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
