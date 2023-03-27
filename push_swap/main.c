/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/27 20:22:05 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	while (tmp != head)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int	creat_stack(t_stack *stack_head, int element_num, t_array *array)
{
	int		i;
	t_stack	*stack;

	i = 1;
	while (i < element_num + 1)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			return (ft_free(stack_head));
		stack->num = array[i].num;
		insert(stack_head, stack);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a_head;
	t_array	*array;

	a_head.next = &a_head;
	a_head.prev = &a_head;
	array = pre_sort(argc - 1, argv);
	if (!array)
		return (1);
	if (argc <= 2)
		return (array_free(array));
	if (creat_stack(&a_head, argc - 1, array) != 0)
		return (array_free(array));
	array_free(array);
	if (is_sorted(&a_head) == 0)
		return (ft_free(&a_head));
	if (argc <= 4)
		only_three_elements(&a_head);
	else if (argc <= 7)
		only_six_elements(&a_head, argc - 1);
	else
		push_swap(&a_head, argc - 1);
	return (ft_free(&a_head));
}
