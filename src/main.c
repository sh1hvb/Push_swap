/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:35:44 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/12 14:24:23 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// #include <crtdbg.h>

// static int howin(char **av)
// {
// 	int i = 0;
// 	while(av[i++] != NULL)
// 		i++;
// 	return (i);
// }

void	init_stack(t_stk **stack, int argc, char **argv)
{
	t_stk	*new;
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			new = ft_lstnew(ft_atoi(args[j]));
			ft_lstadd_back(stack, new);
			j++;
		}
		ft_free(args);
		i++;
	}
	index_stack(stack);
}

static void	sort_stack(t_stk **stack_a, t_stk **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stk	**stack_a;
	t_stk	**stack_b;

	// _CrtSetDbgFlag(_CRTDB_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (argc < 2)
		return (-1);
	// printf("%d",howin(argv));
	// if(howin(argv) == 1)
	// 	return(0);
	ft_check_args(argc, argv);
	stack_a = (t_stk **)malloc(sizeof(t_stk));
	stack_b = (t_stk **)malloc(sizeof(t_stk));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	printList(*stack_a);
	printf("%d\n", ft_lstsize(*stack_a));
	free_stack(stack_a);
	free_stack(stack_b);
	
	
	return (0);
}
// system("valgrind --leak-check=full --track-origins=yes ./push_swap");
