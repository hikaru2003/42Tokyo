/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/28 20:30:52 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*pre_sort(int element_num, char **argv)
{
	t_array	*array;
	int	i;
	int	count;
	int	min;
	int	min_index;
	int	compact_num;

	i = 0;
	count = 0;
	compact_num = 0;
	min = INT_MAX;
	min_index = 0;
	array = (t_array *)malloc(sizeof(t_array) * element_num);
	if (!array)
		return NULL;
	while (i < element_num)
	{
		array[i].num = ft_atoi(argv[i + 1]);
		array[i].flag = 0;
		i++;
	}
	while (count < element_num)
	{
		i = 0;
		min = INT_MAX;
		while (i < element_num)
		{
			if (array[i].flag != 1 && array[i].num < min)
			{
				min = array[i].num;
				min_index = i;
			}
			i++;
		}
		array[min_index].num = count;
		array[min_index].flag = 1;
		count++;
	}
	return (array);
}

int	split_half(t_stack *a_head, t_stack *b_head, int element_num)
{
	t_stack		*tmp;
	int			count;
	int			rotate_count;
	static int	pivot;

	count = pivot;
	pivot = (pivot + element_num) / 2;
	rotate_count = 0;
	tmp = a_head->next;
	while (count < element_num)
	{
		if (tmp->num < pivot)
			push_to_b(a_head, b_head);
		else
		{
			ra(a_head);
			rotate_count++;
		}
		tmp = a_head->next;
		count++;
	}
	while (rotate_count)
	{
		rra(a_head);
		rotate_count--;
	}
	return (pivot);
}

int	find_min(t_stack *head)
{
	t_stack	*tmp;
	int		min;

	// if (head->next == head)  //return値整数を返すとエラーかどうか判定できない
	tmp = head->next;
	min = INT_MAX;
	while (tmp != head)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

void	rtn_b2a_bottom(t_stack *a_head, t_stack *b_head)
{
	t_stack	*save_b_head;
	t_stack	*tmp;
	int		min;

	save_b_head = b_head;
	tmp = b_head->next;
	min = find_min(b_head);
	while (b_head->next != save_b_head)
	{
		if (tmp->num == min)
		{
			push_to_a(a_head, save_b_head);
			ra(a_head);
			min++;
		}
		else
			rb(b_head);
		tmp = save_b_head->next;
	}
}

void	push_swap(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	t_stack	*b;
	int		pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	pivot = 0;
	while (pivot != element_num - 1)
	{
		pivot = split_half(a_head, &b_head, element_num);
		// printf("stack b\n");
		// b = b_head.next;
		// while (b != &b_head)
		// {
		// 	printf("%d\n", b->num);
		// 	b = b->next;
		// }
		rtn_b2a_bottom(a_head, &b_head);
	}
	ra(a_head);
}
