/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:34:24 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/02 20:54:52 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_array
{
	int	num;
	int	flag;
} t_array;

static int	check_flow(long sum, char c, int flag);
int			ft_atoi(const char *str);
void		insert(t_stack *stack, t_stack *new);
void		pop(t_stack *stack);
void		insert(t_stack *stack, t_stack *new);
void		pop(t_stack *stack);
void		push_to(t_stack *to, t_stack *from);
void		push_to_a(t_stack *a, t_stack *b);
void		push_to_b(t_stack *a, t_stack *b);
void		rotate(t_stack *head);
void		ra(t_stack *a_head);
void		rb(t_stack *b_head);
void		rr(t_stack *a_head, t_stack *b_head);
void		reverse_rotate(t_stack *head);
void		rra(t_stack *a_head);
void		rrb(t_stack *b_head);
void		rrr(t_stack *a_head, t_stack *b_head);
void		swap(t_stack *stack);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

t_array		*pre_sort(int element_num, char **argv);
void		push_swap(t_stack *a_head, int element_num);

#endif