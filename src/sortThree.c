/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortThree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:50:34 by mchihab           #+#    #+#             */
/*   Updated: 2024/02/07 21:52:00 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_3_case_1(t_stk **stack_a)
{
    ra(stack_a);
    sa(stack_a);
    rra(stack_a);
}

static void sort_3_case_2(t_stk **stack_a, int bl)
{
    if (bl == 0)
        sa(stack_a);
    else if (bl == 1)
        rra(stack_a);
}

static void sort_3_case_3(t_stk **stack_a, int min)
{
    if ((*stack_a)->next->index == min)
        ra(stack_a);
    else
    {
        sa(stack_a);
        rra(stack_a);
    }
}

void sort_3(t_stk **stack_a)
{
    int min = get_min(stack_a, -1);
    int next_min = get_min(stack_a, min);

    if (is_sorted(stack_a))
        return;

    if ((*stack_a)->index == min && (*stack_a)->next->index != next_min)
        sort_3_case_1(stack_a);
    else if ((*stack_a)->index == next_min)
    {
        int check = ((*stack_a)->next->index == min) ? 1 : 0;
        sort_3_case_2(stack_a, check);
    }
    else 
        sort_3_case_3(stack_a, min);
}
