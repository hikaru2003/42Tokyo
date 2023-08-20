/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:28:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/20 11:00:13 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unset(char *cmd, int *status)
{
	if (!is_alpha_under(*cmd))
	{
		ft_dprintf(1, "bash: unset: `%s': not a valid identifier\n", cmd);
		*status = 1;
		return (FALSE);
	}
	return (TRUE);
}

int	ft_unset(char **cmd, t_list *env_head, int *last_status)
{
	int		i;
	t_list	*tmp;
	int		status;

	i = 1;
	tmp = env_head->next;
	status = *last_status;
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
