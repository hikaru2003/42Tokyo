/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:13:09 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 21:45:13 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_stack *stack, t_stack *new)
{
	new->prev = stack->prev;
	stack->prev->next = new;
	stack->prev = new;
	new->next = stack;
}

void	pop(t_stack *stack)
{
	stack->prev->next = stack->next;
	stack->next->prev = stack->prev;
}

void	push_to(t_stack *to_head, t_stack *from_head)
{
	t_stack	*tmp;

	if (from_head == NULL || from_head->next == from_head)
		return ;
	tmp = from_head->next;
	pop(from_head->next);
	insert(to_head->next, tmp);
}

void	push_to_a(t_stack *a_head, t_stack *b_head)
{
	push_to(a_head, b_head);
	printf("pa\n");
}

void	push_to_b(t_stack *a_head, t_stack *b_head)
{
	push_to(b_head, a_head);
	printf("pb\n");
}

// int	main(int argc, char **argv){
// 	t_stack	a_head;
// 	t_stack	b_head;
// 	t_stack	*a;
// 	t_stack	*b;
// 	int	i;

// 	i = 1;
// 	a_head.next = &a_head;
// 	a_head.prev = &a_head;
// 	b_head.next = &b_head;
// 	b_head.prev = &b_head;

// 	//input num -> stack a
// 	while (i < argc)
// 	{
// 		a = (t_stack *)malloc(sizeof(t_stack));
// 		a->num = ft_atoi(argv[i]);
// 		insert(&a_head, a);
// 		i++;
// 	}
// 	a = a_head.next;
// 	while (a != &a_head)
// 	{
// 		printf("a_num : %d\n", a->num);
// 		a = a->next;
// 	}
// 	push_to(&b_head, &a_head);
// 	printf("push_to\n");
// 	a = a_head.next;
// 	while (a != &a_head)
// 	{
// 		printf("a_num : %d\n", a->num);
// 		a = a->next;
// 	}
// 	b = b_head.next;
// 	while (b != &b_head)
// 	{
// 		printf("b : %d\n", b->num);
// 		b = b->next;
// 	}
// }