/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:51:05 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/22 16:26:34 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_taget_nodes(t_stack **a, t_stack **b)
{
	t_stack	*crt_a;
	t_stack	*crt_b;
	t_stack	*target_node;
	long	best_match_num;

	crt_b = *b;
	while (crt_b)
	{
		best_match_num = LONG_MAX;
		crt_a = (*a);
		while (crt_a)
		{
			if (crt_a->number > crt_b->number && crt_a->number > best_match_num)
			{
				best_match_num = crt_a->number;
				target_node = crt_a;
			}
			crt_a = crt_a->next;
		}
		if (best_match_num == LONG_MAX)
			crt_b->target = find_smallest(a);
		else
			crt_b->target = target_node;
		crt_b = crt_b->next;
	}
}

void	set_positions(t_stack **stack)
{
	int	i;
	int	median;

	if (!(*stack))
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (*stack)
	{
		(*stack)->pos = i;
		(*stack)->below_median = true;
		if ((*stack)->pos > median)
			(*stack)->below_median = false;
		i++;
		*stack = *stack->next;
	}
}

void	calc_cost(t_stack **a, t_stack **b)
{
	int	len_a;
	int	len_b;

	if (!(*a) || !(*b))
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (*b)
	{
		(*b)->push_cost = (*b)->pos;
		if ((*b)->below_median == false)
			(*b)->push_cost = len_b - (*b)->pos;
		if ((*b)->target->below_median == false)
			(*b)->push_cost += len_a - ((*b)->target->pos);
		else
			(*b)->push_cost += (*b)->target->push_cost;
		(*b) = (*b)->next;
	}
}

t_stack	*find_cheapest(t_stack **b)
{
	t_stack	*cheapest_node;
	int		cheapest_push_cost;

	if (!(*b))
		return (NULL);
	cheapest_node = (*b);
	cheapest_push_cost = INT_MAX;
	while (*b)
	{
		if ((*b)->push_cost < cheapest_push_cost)
		{
			cheapest_node = (*b);
			cheapest_node = (*b)->push_cost;
		}
		(*b) = (*b)->next;
	}
	return (cheapest_node);
}
