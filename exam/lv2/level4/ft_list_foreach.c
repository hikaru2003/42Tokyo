/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:00:35 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 19:36:28 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void	func(void *none)
{
	if (!none)
		printf("I'm func!\n");
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

int	main(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->next = NULL;
	list->data = NULL;
	ft_list_foreach(list, func);
	free(list);
	return (0);
}