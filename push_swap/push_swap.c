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

void	*print_error()
{
	write(2, "Error\n", 6);
	exit(1);
	return (NULL);
}

t_array	*scale_down(t_array *array, int min_index, int element_num)
{
	int	count;
	int	i;

	count = 0;
	while (count < element_num)
	{
		i = 1;
		min_index = 0;
		while (i < element_num + 1)
		{
			if (array[i].num == array[min_index].num)
				return ((t_array *)print_error());
			if (array[i].flag != 1 && array[i].num < array[min_index].num)
				min_index = i;
			i++;
		}
		array[min_index].num = count;
		array[min_index].flag = 1;
		count++;
	}
	return (array);
}

t_array	*pre_sort(int element_num, char **argv)
{
	t_array	*array;
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	array = (t_array *)malloc(sizeof(t_array) * (element_num + 1));
	if (!array)
		return NULL;
	array[0].num = INT_MAX;
	while (i < element_num + 1)
	{
		array[i].num = ft_atoi(argv[i]);
		// if (array[i].num == (int)LONG_MAX || array[i].num == (int)LONG_MIN) //0もはじいてしまうのでft_atoiの中でオーバーフロウなどはprint_errorして、print_errorはNULLをかえしたりするのではなく、exitしてしまう．exitしてもいいのか？？？
		// 	return ((t_array *)print_error());
		array[i].flag = 0;
		i++;
	}
	return (scale_down(array, min_index, element_num));
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
	if (a_head->next->num == element_num - 1 ||a_head->next->num == element_num - 2 || a_head->next->num == element_num - 3)
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
		prev_pivot = grouping(a_head, &b_head, a_head->prev->num, prev_pivot, element_num);
	}
	only_three_elements(a_head);
	sort(a_head, &b_head, element_num);
}