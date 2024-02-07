/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:50:27 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/07 17:18:35 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_sa(t_stk **stack_a)
{
	swap(stack_a);
	return (0);
}

int	process_sb(t_stk **stack_b)
{
	swap(stack_b);
	return (0);
}

int	process_ss(t_stk **stack_a, t_stk **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (0);
}

int	process_pa(t_stk **stack_a, t_stk **stack_b)
{
	push(stack_a, stack_b);
	return (0);
}

int	process_pb(t_stk **stack_b, t_stk **stack_a)
{
	push(stack_b, stack_a);
	return (0);
}
