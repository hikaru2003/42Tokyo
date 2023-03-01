/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/28 20:30:52 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char ** argv)
{
	t_stack	a_head;
	t_stack	b_head;
	t_stack	*a;
	t_stack	*b;
	int	i;
	
	i = 1;
	a_head.next = &a_head;
	a_head.prev = &a_head;
	b_head.next = &b_head;
	b_head.prev = &b_head;

	while (i < argc)
	{
		a = (t_stack *)malloc(sizeof(t_stack));
		a->num = ft_atoi(argv[i]);
		insert(&a_head, a);
		i++;
	}
	a = a_head.next;
	while (a != &a_head)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	sa(a_head.next);
	a = a_head.next;
	while (a != &a_head)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	return (0);
}
