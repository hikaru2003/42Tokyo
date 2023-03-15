/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:12:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 21:47:14 by hmorisak         ###   ########.fr       */
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

int	ft_free(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = head->next;
	tmp_next = tmp->next;
	while (tmp != head)
	{
		pop(tmp);
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
	}
	return (1);
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
	if (argc <= 2)
		return (0);
	array = pre_sort(argc - 1, argv);
	if (!array)
		return (1);
	if (creat_stack(&a_head, argc - 1, array) != 0)
		return (1);
	if (is_sorted(&a_head) == 0)
	{
		printf("stack a is alreadly sorted or no input\n");
		return (0);
	}
	if (argc <= 4)
		only_three_elements(&a_head);
	else if (argc <= 7)
		only_six_elements(&a_head, argc - 1);
	else
		push_swap(&a_head, argc - 1);
	return (0);
}

// int	main(int argc, char ** argv)
// {
// 	t_stack	a_head;
// 	t_array	*array;

// 	a_head.next = &a_head;
// 	a_head.prev = &a_head;
// 	if (argc <= 2)
// 		return (0);
// 	array = pre_sort(argc - 1, argv);
// 	if (!array)
// 		return (1); //return値はゼロ？正常終了でいいのか？
// 	if (creat_stack(&a_head, argc - 1, array) != 0)
// 		return (1);
// 	if (is_sorted(&a_head) == 0)
// 		return (0);
// 	if (argc <= 4)
// 		only_three_elements(&a_head);
// 	else if (argc <= 7)
// 		only_six_elements(&a_head, argc - 1);
// 	else
// 		push_swap(&a_head, argc - 1);
// 	return (0);
// }
