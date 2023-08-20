/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:28:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/19 16:44:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unset(char *cmd, int *status)
{
	int	i;

	i = 1;
	if (!is_alpha_under(*cmd))
	{
		ft_dprintf(1, "bash: unset: `%s': not a valid identifier\n", cmd);
		*status = 1;
		return (FALSE);
	}
	while (cmd[i])
	{
		if (!('a' <= cmd[i] && cmd[i] <= 'z')
			&& !('A' <= cmd[i] && cmd[i] <= 'Z')
			&& cmd[i] != '_' && !('0' <= cmd[i] && cmd[i] <= '9'))
		{
			ft_dprintf(1, "bash: unset: `%s': not a valid identifier\n", cmd);
			*status = 1;
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	ft_unset(char **cmd, t_list *env_head)
{
	int		i;
	t_list	*tmp;
	int		status;

	i = 1;
	tmp = env_head->next;
	status = 0;
	while (cmd[i])
	{
		if (check_unset(cmd[i], &status))
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
	return (status);
}
