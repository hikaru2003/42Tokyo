/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:13:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/27 19:51:32 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_three_elements(t_stack *a_head)
{
	int	min;

	min = find_min(a_head, 3);
	if (a_head->next->num == min && a_head->next->next->num == min + 2)
	{
		rra(a_head);
		sa(a_head);
	}
	else if (a_head->next->num == min + 1 && a_head->next->next->num == min)
		sa(a_head);
	else if (a_head->next->num == min + 1)
		rra(a_head);
	else if (a_head->next->num == min + 2 && a_head->next->next->num == min)
		ra(a_head);
	else if (a_head->next->num == min + 2)
	{
		sa(a_head);
		rra(a_head);
	}
}

void	only_six_elements(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	int		pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	pivot = element_num - 3;
	while (a_head->next->next->next->next != a_head)
	{
		if (a_head->next->num < pivot)
			push_to_b(a_head, &b_head);
		else
			ra(a_head);
	}
	only_three_elements(a_head);
	while (b_head.next != &b_head)
	{
		if (b_head.next->num == a_head->next->num - 1)
			push_to_a(a_head, &b_head);
		else
			rb(&b_head);
	}
}

int	find_max_pos(t_stack *b_head, int max, int element_num)
{
	t_stack	*tmp;
	int		count;

	tmp = b_head->next;
	count = 0;
	while (tmp != b_head)
	{
		if (tmp->num == max && count < element_num / 2)
			return (TOP);
		if (tmp->num == max)
			return (BOTTOM);
		tmp = tmp->next;
		count++;
	}
	return (-1);
}

void	sort(t_stack *a_head, t_stack *b_head, int element_num)
{
	int	max;
	int	flag;

	max = element_num - 4;
	while (b_head->next != b_head)
	{
		flag = max_to_a(a_head, b_head, max,
				find_max_pos(b_head, max, element_num));
		if (flag == 1)
		{
			max -= 2;
			element_num -= 2;
		}
		else
		{
			max -= 1;
			element_num -= 1;
		}
	}
}
