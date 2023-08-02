/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:28:54 by hikaru            #+#    #+#             */
/*   Updated: 2023/07/21 18:39:29 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_list *env_head)
{
	t_list	*tmp;

	tmp = env_head->next;
	while (tmp != env_head)
	{
		if (strcmp(tmp->value, "\0"))
			dprintf(STDOUT_FILENO, "%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (TRUE);
}
