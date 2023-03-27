/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:09:51 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/27 20:21:24 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_free(t_array *array)
{
	free(array);
	return (0);
}

int	ft_free(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = head->next;
	tmp_next = tmp->next;
	while (tmp != head)
	{
		pop(tmp);
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
	}
	return (1);
}
