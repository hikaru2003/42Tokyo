/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:03:24 by hikaru            #+#    #+#             */
/*   Updated: 2023/05/03 19:27:51 by hikaru           ###   ########.fr       */
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
	free(list->env);
	free(list);
	head->count--;
}

t_list	*free_list(t_list *head)
{
	t_list	*list;
	t_list	*tmp;

	list = head->next;
	tmp = list;
	while (list != head)
	{
		tmp = list->next;
		free(list->env);
		free(list);
		list = tmp;
	}
	return (NULL);
}

t_list	*env_to_list(void)
{
	t_list	*head;
	t_list	*list;
	int		i;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->count = 0;
	head->next = head;
	head->prev = head;
	i = 0;
	while (environ[i])
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->env = ft_strjoin("", environ[i]);
		if (!list->env)
			return (free_list(head));
		insert(head, list);
		i++;
	}
	return (head);
}