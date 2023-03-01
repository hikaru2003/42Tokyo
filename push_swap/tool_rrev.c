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
	rra(a_head);
	rrb(b_head);
	printf("rrr\n");
}
