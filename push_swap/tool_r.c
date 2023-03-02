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