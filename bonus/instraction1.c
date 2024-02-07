/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:57:59 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/07 16:15:27 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_ra(t_stk **stack_a)
{
	rotate(stack_a);
	return (0);
}

int	process_rb(t_stk **stack_b)
{
	rotate(stack_b);
	return (0);
}

int	process_rr(t_stk **stack_a, t_stk **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return (0);
}

int	process_rra(t_stk **stack_a)
{
	reverseRotate(stack_a);
	return (0);
}

int	process_rrb(t_stk **stack_b)
{
	reverseRotate(stack_b);
	return (0);
}
