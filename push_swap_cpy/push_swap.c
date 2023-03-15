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

void	push_last_num(t_stack *a_head, t_stack *b_head, t_pivot pivot, int element_num)
{
	if (a_head->next->num == element_num - 1
		|| a_head->next->num == element_num - 2
		|| a_head->next->num == element_num - 3)
		ra(a_head);
	else if (a_head->next->num < pivot.current)
	{
		push_to_b(a_head, b_head);
		if (b_head->next->num < (pivot.prev + pivot.current) / 2)
			rb(b_head);
	}
}

int	last_three_elements(t_stack *a_head, int element_num)
{
	if (a_head->next->num == element_num - 1
		|| a_head->next->num == element_num - 2
		|| a_head->next->num == element_num - 3)
		return (1);
	return (0);
}

void	under_pivot(t_stack *a_head, t_stack *b_head, t_pivot pivot)
{
	push_to_b(a_head, b_head);
	if ((b_head->next->num < (pivot.prev + pivot.current) / 2)
		&& a_head->next->num >= pivot.current)
		rr(a_head, b_head);
	else if (b_head->next->num < (pivot.prev + pivot.current) / 2)
		rb(b_head);
}

int	grouping(t_stack *a_head, t_stack *b_head, t_pivot pivot, int element_num)
{
	static int	i;
	int			last_num;

	if (i == 0)
		i = 1;
	pivot.current = element_num * i / (3 + element_num / 100);
	last_num = a_head->prev->num;
	if (i == (3 + element_num / 100) + 1)
		return (0);
	while (a_head->next->num != last_num)
	{
		if (last_three_elements(a_head, element_num) == 1)
			ra(a_head);
		else if (a_head->next->num < pivot.current)
			under_pivot(a_head, b_head, pivot);
		else
			ra(a_head);
	}
	push_last_num(a_head, b_head, pivot, element_num);
	i++;
	return (pivot.current);
}

void	push_swap(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	t_pivot	pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	pivot.current = 0;
	pivot.prev = grouping(a_head, &b_head, pivot, element_num);
	while (pivot.prev != 0)
	{
		pivot.prev = grouping(a_head, &b_head, pivot, element_num);
	}
	only_three_elements(a_head);
	sort(a_head, &b_head, element_num);
}
