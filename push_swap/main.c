#include "push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	while (tmp != head)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int	ft_free(t_stack *head)
{
	t_stack *tmp;

	tmp = head;
	head = head->next;
	while (head != tmp)
	{
		free(head);
		head = head->next;
	}
	return (1);
}

int	creat_stack(t_stack *stack_head, int element_num, t_array *array)
{
	int		i;
	t_stack	*stack;

	i = 0;
	while (i < element_num)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (!stack)
			return (ft_free(stack_head));
		stack->num = array[i].num;
		insert(stack_head, stack);
		i++;
	}
	return (0);
}

int	main(int argc, char ** argv)
{
	t_stack	a_head;
	// t_stack	*a;
	t_array	*array;

	a_head.next = &a_head;
	a_head.prev = &a_head;
	//input compact num(start from 0) -> stack a
	array = pre_sort(argc - 1, argv);
	if (creat_stack(&a_head, argc - 1, array) != 0)
		return (1);
	printf("stack a -> ");
	print_stack(&a_head);
	if (is_sorted(&a_head) == 0)
	{
		printf("stack a is alreadly sorted\n");
		return (0);
	}
	if (argc <= 4)
		only_three_elements(&a_head);
	else if (argc <= 7)
		only_six_elements(&a_head, argc - 1);
	else
		push_swap(&a_head, argc - 1);
	printf("stack a -> ");
	print_stack(&a_head);
	if (is_sorted(&a_head) == 0)
	{
		printf("stack a is sorted\n");
		return (0);
	}
	return (0);
}