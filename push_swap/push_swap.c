/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/02 20:56:13 by hmorisak         ###   ########.fr       */
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

	i = 0;
	count = 0;
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