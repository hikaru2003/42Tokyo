/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_rrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:14 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/02 20:55:15 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *head)
{
	t_stack	*tmp;
	int		last_num;

	if (head == NULL)
		return ;
	tmp = head->prev;
	last_num = tmp->num;
	while (tmp->prev != head)
	{
		tmp->num = tmp->prev->num;
		tmp = tmp->prev;
	}
	tmp->num = last_num;
}

void	rra(t_stack *a_head)
{
	reverse_rotate(a_head);
	printf("rra\n");
}

void	rrb(t_stack *b_head)
{
	reverse_rotate(b_head);
	printf("rrb\n");
}

void	rrr(t_stack *a_head, t_stack *b_head)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
	printf("rrr\n");
}
