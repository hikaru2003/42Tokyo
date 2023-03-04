/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/02 20:58:10 by hmorisak         ###   ########.fr       */
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
	free(stack); //freeするのか？
}

void	p_to(t_stack *to, t_stack *from)
{
	t_stack	*new;

	if (from == NULL)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;//free(all)するのか？
	new->num = from->num;
	insert(to, new);
	pop(from);
}

void	pa(t_stack *a, t_stack *b)
{
	p_to(a, b);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	p_to(b, a);
	printf("pb\n");
}
