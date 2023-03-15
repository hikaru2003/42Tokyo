/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 09:15:24 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*pre_sort(int element_num, char **argv)
{
	t_array	*array;
	int		i;
	int		count;
	int		min;
	int		min_index;

	i = 0;
	count = 0;
	min = INT_MAX;
	min_index = 0;
	array = (t_array *)malloc(sizeof(t_array) * element_num);
	if (!array)
		return (NULL);
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
	// printf("pivot=%d\n", pivot);
	while (count < element_num)
	{
		// if (tmp->num > tmp->next->num)
		// 	sa(a_head);
		if (tmp->num < pivot)
		{
			push_to_b(a_head, b_head);
			// printf("after_push_to_b %d\n", tmp->num);
		}
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

int	find_min(t_stack *head, int count)
{
	t_stack	*tmp;
	int		min;
	int		i;

	// if (head->next == head)  //return値整数を返すとエラーかどうか判定できない
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

void	rtn_b2a_bottom(t_stack *a_head, t_stack *b_head)
{
	t_stack	*save_b_head;
	t_stack	*tmp;
	int		min;

	save_b_head = b_head;
	tmp = b_head->next;
	min = find_min(b_head, INT_MAX);
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

void	sort_three_elements(t_stack *a_head, t_stack *b_head)
{
	int	min;

	min = find_min(a_head, 3);
	// printf("min = %d\n", min);
	if (a_head->next->num == min)
	{
		ra(a_head);
		if (a_head->next->num == min + 1)
		{
			ra(a_head);
			ra(a_head);
		}
		else
		{
			sa(a_head);
			ra(a_head);
			ra(a_head);
		}
	}
	else if (a_head->next->num == min + 1)
	{
		if (a_head->next->next->num == min)
		{
			sa(a_head);
			ra(a_head);
			ra(a_head);
			ra(a_head);
		}
		else
		{
			push_to_b(a_head, b_head);
			push_to_b(a_head, b_head);
			ra(a_head);
			push_to_a(a_head, b_head);
			push_to_a(a_head, b_head);
			ra(a_head);
			ra(a_head);
		}
	}
	else
	{
		if (a_head->next->next->num == min)
		{
			push_to_b(a_head, b_head);
			ra(a_head);
			ra(a_head);
			push_to_a(a_head, b_head);
			ra(a_head);
		}
		else
		{
			push_to_b(a_head, b_head);
			sa(a_head);
			ra(a_head);
			ra(a_head);
			push_to_a(a_head, b_head);
			ra(a_head);
		}
	}
}

// void	push_swap(t_stack *a_head, int element_num)
// {
// 	t_stack	b_head;
// 	int		pivot;

// 	b_head.next = &b_head;
// 	b_head.prev = &b_head;
// 	pivot = 0;
// 	while (element_num - pivot > 3)
// 	{
// 		pivot = split_half(a_head, &b_head, element_num);
// 		// t_stack	*b;
// 		// printf("stack b\n");
// 		// b = b_head.next;
// 		// while (b != &b_head)
// 		// {
// 		// 	printf("%d\n", b->num);
// 		// 	b = b->next;
// 		// }
// 		rtn_b2a_bottom(a_head, &b_head);
// 	}

// 	//print stack a
// 	// t_stack	*a;
// 	// a = a_head->next;
// 	// printf("stack a\n");
// 	// while (a != a_head)
// 	// {
// 	// 	printf("%d\n", a->num);
// 	// 	a = a->next;
// 	// }
// 	sort_three_elements(a_head, &b_head);
// }

int	grouping(t_stack *a_head, t_stack *b_head, int prev_pivot, int element_num)
{
	static int	i;
	int			devide_num;
	int			pivot;
	int			last_num;

	if (i == 0)
		i = 1;
	devide_num = 3 + element_num / 100;
	last_num = a_head->prev->num;
	pivot = element_num * i / devide_num;
	if (i == devide_num + 1)
		return (0);
	while (a_head->next->num != last_num)
	{
		if (a_head->next->num == element_num - 1 ||a_head->next->num == element_num - 2 || a_head->next->num == element_num - 3)
			ra(a_head);
		else if (a_head->next->num < pivot)
		{
			push_to_b(a_head, b_head);
			if ((b_head->next->num < (prev_pivot + pivot) / 2) && a_head->next->num >= pivot)
				rr(a_head, b_head);
			else if (b_head->next->num < (prev_pivot + pivot) / 2)
				rb(b_head);
		}
		else
			ra(a_head);
	}
	if (a_head->next->num == element_num - 1 ||a_head->next->num == element_num - 2 || a_head->next->num == element_num - 3)
			ra(a_head);
	else if (a_head->next->num < pivot)
	{
		push_to_b(a_head, b_head);
		if (b_head->next->num < (prev_pivot + pivot) / 2)
			rb(b_head);
	}
	i++;
	return (pivot);
}

void	push_swap(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	int		prev_pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	prev_pivot = grouping(a_head, &b_head, 0, element_num);
	while (prev_pivot != 0)
	{
		prev_pivot = grouping(a_head, &b_head, prev_pivot, element_num);
	}
	only_three_elements(a_head);
	sort(a_head, &b_head, element_num);
}