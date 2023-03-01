#include "push_swap.h"

void	rotate(t_stack *head)
{
	t_stack	*tmp;
	int		top_num;

	if (head == NULL)
		return ;
	tmp = head->next;
	top_num = tmp->num;
	while (tmp->next != head)
	{
		tmp->num = tmp->next->num;
		tmp = tmp->next;
	}
	tmp->num = top_num;
}

void	ra(t_stack *a_head)
{
	rotate(a_head);
	printf("ra\n");
}

void	rb(t_stack *b_head)
{
	rotate(b_head);
	printf("rb\n");
}

void	rr(t_stack *a_head, t_stack *b_head)
{
	ra(a_head);
	rb(b_head);
	printf("rr\n");
}
