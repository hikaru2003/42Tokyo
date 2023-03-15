/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_to_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:42:24 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/15 21:42:55 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_on_top(t_stack *a_head, t_stack *b_head, int max)
{
	int	flag;

	flag = 0;
	while (b_head->next->num != max)
	{
		if (b_head->next->num == max - 1)
		{
			push_to_a(a_head, b_head);
			flag = 1;
		}
		else
			rb(b_head);
	}
	return (flag);
}

int	max_on_bottom(t_stack *a_head, t_stack *b_head, int max)
{
	int	flag;

	flag = 0;
	while (b_head->next->num != max)
	{
		if (b_head->next->num == max - 1)
		{
			push_to_a(a_head, b_head);
			flag = 1;
		}
		else
			rrb(b_head);
	}
	return (flag);
}

// もし最大値ー1を見つけたら先にAにプッシュする．そのあと最大値をプッシュしてAをスワップする
// 並び方によっては一回のループで二個ソートできるときもある
int	max_to_a(t_stack *a_head, t_stack *b_head, int max, int pos)
{
	int	flag;

	flag = 0;
	if (pos == TOP)
		flag = max_on_top(a_head, b_head, max);
	else
	{
		flag = max_on_bottom(a_head, b_head, max);
	}
	push_to_a(a_head, b_head);
	if (flag == 1)
		sa(a_head);
	return (flag);
}
