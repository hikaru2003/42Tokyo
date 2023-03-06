#include "push_swap.h"

int	main(int argc, char ** argv)
{
	t_stack	a_head;
	t_stack	*a;
	int	i;
	t_array	*array;
	
	i = 1;
	a_head.next = &a_head;
	a_head.prev = &a_head;

	//input compact num(start from 0) -> stack a
	array = pre_sort(argc - 1, argv);
	i = 0;
	while (i < argc - 1)
	{
		a = (t_stack *)malloc(sizeof(t_stack));
		a->num = array[i].num;
		insert(&a_head, a);
		i++;
	}
	//print stack a
	a = a_head.next;
	while (a != &a_head)
	{
		printf("%d\n", a->num);
		a = a->next;
	}

	//check if stack a is alreadly sorted
	if (is_sorted(&a_head) == 0)
	{
		printf("stack a is alreadly sorted\n");
		return (0);
	}
	//element num <= 3
	if (argc <= 4)
		only_three_elements(&a_head);
	//element num <= 6
	else if (argc <= 7)
		only_six_elements(&a_head, argc - 1);
	else
	{
		push_swap(&a_head, argc - 1);
		printf("push swap\n");
	}
	printf("stack a\n");
	a = a_head.next;
	while (a != &a_head)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	return (0);
}