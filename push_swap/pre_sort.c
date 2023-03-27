/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:20:17 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/27 20:02:09 by hmorisak         ###   ########.fr       */
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
	int		i;
	int		min_index;

	i = 1;
	min_index = 0;
	array = (t_array *)malloc(sizeof(t_array) * (element_num + 2));
	if (!array)
		return (NULL);
	array[0].num = LONG_MAX;
	while (i < element_num + 1)
	{
		array[i].num = ft_atoi(argv[i]);
		array[i].flag = 0;
		i++;
	}
	array[i].flag = 2;
	return (scale_down(array, min_index, element_num));
}
