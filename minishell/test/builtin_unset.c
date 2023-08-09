/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:28:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/09 16:22:38 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **cmd, t_list *env_head)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = env_head->next;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '[') || ft_strchr(cmd[i], ']'))
		{
			dprintf(1, "bash: unset: `%s': not a valid identifier\n", cmd[i]);
			g_var.g_last_status = 1;
		}
		else
		{
			tmp = env_head->next;
			while (tmp != env_head)
			{
				if (ft_strcmp(cmd[i], tmp->key) == 0)
				{
					delete(env_head, tmp);
					break ;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (g_var.g_last_status);
}
