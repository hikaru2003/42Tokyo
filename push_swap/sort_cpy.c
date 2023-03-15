/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:13:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 09:13:01 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a_head)
{
	t_stack	*tmp;

	tmp = a_head->next;
	while (tmp != a_head && tmp->next != a_head)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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
	int 	count;

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

// もし最大値ー1を見つけたら先にAにプッシュする．そのあと最大値をプッシュしてAをスワップする
// 並び方によっては一回のループで二個ソートできるときもある
int	max_to_a(t_stack *a_head, t_stack *b_head, int max, int pos)
{
	int	flag;

	flag = 0;
	if (pos == TOP)
	{
		while (b_head->next->num != max)
		{
			if (b_head->next->num == max - 1)
			{
				push_to_a(a_head, b_head);
				flag = 1;
			}
			rb(b_head);
		}
	}
	else
	{
		while(b_head->next->num != max)
		{
			if (b_head->next->num == max - 1)
			{
				push_to_a(a_head, b_head);
				flag = 1;
			}
			rrb(b_head);
		}
	}
	push_to_a(a_head, b_head);
	if (flag == 1)
		sa(a_head);
	return (flag);
}

void	sort(t_stack *a_head, t_stack *b_head, int element_num)
{
	int	max;
	int	flag;

	max = element_num - 1;
	while(b_head->next != b_head)
	{
		flag = max_to_a(a_head, b_head, max, find_max_pos(b_head, max, element_num));
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
