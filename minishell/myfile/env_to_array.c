/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:26:58 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/14 11:27:22 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_array(t_list *env_head)
{
	int		i;
	t_list	*tmp;
	char	**array;

	i = 0;
	tmp = env_head->next;
	array = (char **)malloc(sizeof(char *) * (env_head->count + 1));
	if (!array)
		return (NULL);
	while (i < env_head->count && tmp != env_head)
	{
		array[i] = ft_strdup(tmp->env);
		if (!array[i])
			return (free_array(array));
		i++;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}
