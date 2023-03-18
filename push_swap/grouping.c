/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:24:38 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/18 16:24:39 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_last_num(t_stack *a_head, t_stack *b_head,
	t_pivot pivot, int element_num)
{
	if (a_head->next->num == element_num - 1
		|| a_head->next->num == element_num - 2
		|| a_head->next->num == element_num - 3)
		ra(a_head);
	else if (a_head->next->num < pivot.current)
	{
		push_to_b(a_head, b_head);
		if (b_head->next->num < (pivot.prev + pivot.current) / 2)
			rb(b_head);
	}
}

int	last_three_elements(t_stack *a_head, int element_num)
{
	if (a_head->next->num == element_num - 1
		|| a_head->next->num == element_num - 2
		|| a_head->next->num == element_num - 3)
		return (1);
	return (0);
}

void	under_pivot(t_stack *a_head, t_stack *b_head, t_pivot pivot)
{
	push_to_b(a_head, b_head);
	if ((b_head->next->num < (pivot.prev + pivot.current) / 2)
		&& a_head->next->num >= pivot.current)
		rr(a_head, b_head);
	else if (b_head->next->num < (pivot.prev + pivot.current) / 2)
		rb(b_head);
}

int	grouping(t_stack *a_head, t_stack *b_head, t_pivot pivot, int element_num)
{
	static int	i;
	int			last_num;

	if (i == 0)
		i = 1;
	pivot.current = element_num * i / (3 + element_num / 100);
	last_num = a_head->prev->num;
	if (i == (3 + element_num / 100) + 1)
		return (0);
	while (a_head->next->num != last_num)
	{
		if (last_three_elements(a_head, element_num) == 1)
			ra(a_head);
		else if (a_head->next->num < pivot.current)
			under_pivot(a_head, b_head, pivot);
		else
			ra(a_head);
	}
	push_last_num(a_head, b_head, pivot, element_num);
	i++;
	return (pivot.current);
}
