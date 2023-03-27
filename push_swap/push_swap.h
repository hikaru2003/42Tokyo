/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:34:24 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/27 20:21:37 by hmorisak         ###   ########.fr       */
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

# define TOP 0
# define BOTTOM 1

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_array
{
	long	num;
	int		flag;
}	t_array;

typedef struct s_pivot
{
	int	prev;
	int	current;
}	t_pivot;

//free.c
int			ft_free(t_stack *head);
int			array_free(t_array *array);

//ft_atoi.c
int			ft_atoi(const char *str);

//grouping.c
void		push_last_num(t_stack *a_head, t_stack *b_head,
				t_pivot pivot, int element_num);
int			last_three_elements(t_stack *a_head, int element_num);
void		under_pivot(t_stack *a_head, t_stack *b_head, t_pivot pivot);
int			grouping(t_stack *a_head, t_stack *b_head,
				t_pivot pivot, int element_num);

//main.c
void		print_stack(t_stack *head);
int			creat_stack(t_stack *stack_head, int element_num, t_array *array);

//max_to_a.c
int			max_on_top(t_stack *a_head, t_stack *b_head, int max);
int			max_on_bottom(t_stack *a_head, t_stack *b_head, int max);
int			max_to_a(t_stack *a_head, t_stack *b_head, int max, int pos);

//pre_sort.c
int			is_sorted(t_stack *a_head);
t_array		*scale_down(t_array *array, int min_index, int element_num);
t_array		*pre_sort(int element_num, char **argv);

//push_swap.c
void		*print_error(void);
int			find_min(t_stack *head, int count);
void		push_swap(t_stack *a_head, int element_num);

//sort.c
void		only_three_elements(t_stack *a_head);
void		only_six_elements(t_stack *a_head, int element_num);
int			find_max_pos(t_stack *b_head, int max, int element_num);
void		sort(t_stack *a_head, t_stack *b_head, int element_num);

//tool_.c
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
void		swap(t_stack *head);
void		sa(t_stack *a_head);
void		sb(t_stack *b_head);
void		ss(t_stack *a_head, t_stack *b_head);

#endif