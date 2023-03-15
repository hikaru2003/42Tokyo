/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:09 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 09:13:57 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *head)
{
	t_stack	*tmp;
	int		top_num;

	if (head->next == head)
		return ;
	tmp = head->next;
	top_num = tmp->num;
	while (tmp->next != head)
	{
		tmp->num = tmp->next->num;
		tmp = tmp->next;
	}
	tmp->num = top_num;
}

void	ra(t_stack *a_head)
{
	rotate(a_head);
	printf("ra\n");
}

void	rb(t_stack *b_head)
{
	rotate(b_head);
	printf("rb\n");
}

void	rr(t_stack *a_head, t_stack *b_head)
{
	rotate(a_head);
	rotate(b_head);
	printf("rr\n");
}

// int	main(int argc, char ** argv)
// {
// 	t_stack	*a;
// 	t_stack	a_head;
// 	int	i;
// 	t_array	*array;

// 	i = 1;
// 	a_head.next = &a_head;
// 	a_head.prev = &a_head;
// 	a_head.num = INT_MIN;

// 	array = pre_sort(argc - 1, argv);
// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		a = (t_stack *)malloc(sizeof(t_stack));
// 		a->num = array[i].num;
// 		insert(&a_head, a);
// 		i++;
// 	}
// 	a = a_head.next;
// 	while (a != &a_head)
// 	{
// 		printf("%d\n", a->num);
// 		a = a->next;
// 	}
// 	ra(&a_head);
// 	printf("a_head=%d\n", a_head.num);
// 	printf("a_head_prev=%d\n", a_head.prev->num);
// 	a = a_head.next;
// 	while (a != &a_head)
// 	{
// 		printf("%d\n", a->num);
// 		a = a->next;
// 	}
// 	return (0);
// }