/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:45:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/22 19:32:19 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack	*cheapest, t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b))
		return ;
	while (cheapest->prev != NULL && cheapest->target->prev != NULL)
		rr(a, b);
}

static void	rev_rotate_both(t_stack	*cheapest, t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b))
		return ;
	while (cheapest->prev != NULL && cheapest->target->prev != NULL)
		rrr(a, b);
}

static void	finish_rotation(t_stack	*cheapest, t_stack **stack, char format)
{
	if (!(*stack))
		return ;
	if (cheapest->prev == NULL)
		return ;
	while (cheapest != (*stack))
	{
		if (format == 'a')
		{
			if (cheapest->below_median == true)
				ra(stack);
			else
				rra(stack);
		}
		else if (format == 'b')
		{
			if (cheapest->below_median == true)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_node(t_stack *cheapest, t_stack **a, t_stack **b)
{
	if (cheapest->below_median && cheapest->target->below_median)
		rotate_both(cheapest, a, b);
	else if (!(cheapest->below_median) && !(cheapest->target->below_median))
		rev_rotate_both(cheapest, a, b);
	finish_rotation(cheapest, a, 'a');
	finish_rotation(cheapest, b, 'b');
	pa(a, b);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (stack_len(a) > 3)
		pb(a, b);
	sort_three(a);
	while (!stack_sorted(a) && (*b))
	{
		set_taget_nodes(a, b);
		set_positions(a);
		set_positions(b);
		calc_cost(a, b);
		cheapest = find_cheapest(b);
		move_node(cheapest, a, b);
		pa(a, b);
	}
}
