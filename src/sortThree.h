/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortThree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:50:34 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/08 15:43:52 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTTHREE_H
# define SORTTHREE_H

# include "push_swap.h"

void	sort_3_case_1(t_stk **stack_a);
void	sort_3_case_2(t_stk **stack_a, int bl);
void	sort_3_case_3(t_stk **stack_a, int min);

void	sort_3_case_1(t_stk **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	sort_3_case_2(t_stk **stack_a, int bl)
{
	if (bl == 1)
		sa(stack_a);
	else
		rra(stack_a);
}

void	sort_3_case_3(t_stk **stack_a, int min)
{
	if ((*stack_a)->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

#endif
