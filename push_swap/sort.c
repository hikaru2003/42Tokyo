#include "push_swap.h"

int	is_sorted(t_stack *a_head)
{
	t_stack	*tmp;

	tmp = a_head->next;
	while (tmp != a_head && tmp->next != a_head)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	only_three_elements(t_stack *a_head)
{
	int	min;

	min = find_min(a_head, 3);
	if (a_head->next->num == min && a_head->next->next->num == min + 2)
	{
		rra(a_head);
		sa(a_head);
	}
	else if (a_head->next->num == min + 1 && a_head->next->next->num == min)
		sa(a_head);
	else if (a_head->next->num == min + 1)
		rra(a_head);
	else if (a_head->next->num == min + 2 && a_head->next->next->num == min)
		ra(a_head);
	else if (a_head->next->num == min + 2)
	{
		sa(a_head);
		rra(a_head);
	}
}

void	only_six_elements(t_stack *a_head, int element_num)
{
	t_stack	b_head;
	t_stack	*b;
	int		pivot;

	b_head.next = &b_head;
	b_head.prev = &b_head;
	pivot = element_num - 3;
	while (a_head->next->next->next->next != a_head)
	{
		if (a_head->next->num < pivot)
			push_to_b(a_head, &b_head);
		else
			ra(a_head);
	}
	only_three_elements(a_head);
	while (b_head.next != &b_head)
	{
		if (b_head.next->num == a_head->next->num - 1)
			push_to_a(a_head, &b_head);
		else
			rb(&b_head);
	}
}
