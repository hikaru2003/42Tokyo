/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/24 20:14:25 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return (NULL);
}

int	find_min(t_stack *head, int count)
{
	t_stack	*tmp;
	int		min;
	int		i;

	i = 0;
	tmp = head->next;
	min = INT_MAX;
	while (tmp != head && i < count)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
		i++;
	}
	return (min);
}

void	push_swap(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	t_pivot	pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	pivot.current = 0;
	pivot.prev = 0;
	pivot.prev = grouping(a_head, &b_head, pivot, element_num);
	while (pivot.prev != 0)
	{
		pivot.prev = grouping(a_head, &b_head, pivot, element_num);
	}
	only_three_elements(a_head);
	sort(a_head, &b_head, element_num);
}
