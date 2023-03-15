/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 21:48:45 by hmorisak         ###   ########.fr       */
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

	// if (head->next == head) ありえないから書かなくてもいいか？
	// 	return (-1);
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

void	push_last_num(t_stack *a_head, t_stack *b_head, int prev_pivot, int pivot, int element_num)
{
	if (a_head->next->num == element_num - 1
		|| a_head->next->num == element_num - 2
		|| a_head->next->num == element_num - 3)
		ra(a_head);
	else if (a_head->next->num < pivot)
	{
		push_to_b(a_head, b_head);
		if (b_head->next->num < (prev_pivot + pivot) / 2)
			rb(b_head);
	}
}

int	grouping(t_stack *a_head, t_stack *b_head, int last_num, int prev_pivot, int element_num)
{
	static int	i;
	int			pivot;

	if (i == 0)
		i = 1;
	pivot = element_num * i / (3 + element_num / 100);
	if (i == (3 + element_num / 100) + 1)
		return (0);
	while (a_head->next->num != last_num)
	{
		if (a_head->next->num == element_num - 1
			|| a_head->next->num == element_num - 2
			|| a_head->next->num == element_num - 3)
			ra(a_head);
		else if (a_head->next->num < pivot)
		{
			push_to_b(a_head, b_head);
			if ((b_head->next->num < (prev_pivot + pivot) / 2)
				&& a_head->next->num >= pivot)
				rr(a_head, b_head);
			else if (b_head->next->num < (prev_pivot + pivot) / 2)
				rb(b_head);
		}
		else
			ra(a_head);
	}
	push_last_num(a_head, b_head, prev_pivot, pivot, element_num);
	i++;
	return (pivot);
}

void	push_swap(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	int		prev_pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	prev_pivot = grouping(a_head, &b_head, a_head->prev->num, 0, element_num);
	while (prev_pivot != 0)
	{
		prev_pivot = grouping(a_head, &b_head,
				a_head->prev->num, prev_pivot, element_num);
	}
	only_three_elements(a_head);
	sort(a_head, &b_head, element_num);
}
