/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:28:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/03 18:58:14 by hikaru           ###   ########.fr       */
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
		i++;
	}
	return (0);
}
