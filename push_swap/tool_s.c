/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:55:19 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 09:13:41 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head)
{
	t_stack	*head_next;
	int		tmp;

	head_next = head->next;
	if (head_next == head || head_next->next == head)
		return ;
	tmp = head_next->num;
	head_next->num = head_next->next->num;
	head_next->next->num = tmp;
}

void	sa(t_stack *a_head)
{
	swap(a_head);
	printf("sa\n");
}

void	sb(t_stack *b_head)
{
	swap(b_head);
	printf("sb\n");
}

void	ss(t_stack *a_head, t_stack *b_head)
{
	swap(a_head);
	swap(b_head);
	printf("ss\n");
}
