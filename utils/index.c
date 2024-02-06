
#include "push_swap.h"

static t_stk	*get_next_min(t_stk **stack)
{
	t_stk	*head;
	t_stk	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;  
			}
			head = head->next;
		}
	}
	return (min);
}

void index_stack(t_stk** stack) {
    int index = 0;
	t_stk *min;

    while (1) {
        min = get_next_min(stack);
        if (!min) {
            break;
        }
        min->index = index++;
    }
}

