/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:36:17 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/08 15:34:47 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_rrr(t_stk **stack_a, t_stk **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (0);
}

int	do_commands(char *line, t_stk **stack_a, t_stk **stack_b)
{
	if (!ft_strcmp(line, "sa"))
		return (process_sa(stack_a));
	if (!ft_strcmp(line, "sb"))
		return (process_sb(stack_b));
	if (!ft_strcmp(line, "ss"))
		return (process_ss(stack_a, stack_b));
	if (!ft_strcmp(line, "pa"))
		return (process_pa(stack_a, stack_b));
	if (!ft_strcmp(line, "pb"))
		return (process_pb(stack_b, stack_a));
	if (!ft_strcmp(line, "ra"))
		return (process_ra(stack_a));
	if (!ft_strcmp(line, "rb"))
		return (process_rb(stack_b));
	if (!ft_strcmp(line, "rr"))
		return (process_rr(stack_a, stack_b));
	if (!ft_strcmp(line, "rra"))
		return (process_rra(stack_a));
	if (!ft_strcmp(line, "rrb"))
		return (process_rrb(stack_b));
	if (!ft_strcmp(line, "rrr"))
		return (process_rrr(stack_a, stack_b));
	return (1);
}

void	print_checker_res(t_stk **stack_a, t_stk **stack_b)
{
	if (is_sorted(stack_a) && ((*stack_b) == NULL) == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
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

int	main(int argc, char **argv)
{
	t_stk	**stack_a;
	t_stk	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_stk **)malloc(sizeof(t_stk));
	stack_b = (t_stk **)malloc(sizeof(t_stk));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	init_stack(stack_a, argc, argv);
	while (get_next_line(0, &line))
	{
		if (do_commands(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}
