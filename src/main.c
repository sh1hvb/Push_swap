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
int howin(char **args)
{
	int i = 0;
	while (args[i])
	{
		i++;
	}
	return (i);
}
static void	init_stack(t_stk **stack, int argc, char **argv)
{
	t_stk	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if(howin(args) == 1)
	{
		ft_free(args);
		system("leaks push_swap");
		exit(0);
		
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
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

	if (argc < 2)
		return (-1);
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
