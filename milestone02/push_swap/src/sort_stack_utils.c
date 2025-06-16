/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:51:05 by ilaliev           #+#    #+#             */
/*   Updated: 2025/06/16 21:08:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			if (crt_a->number > crt_b->number && crt_a->number < best_match_num)
			{
				best_match_num = crt_a->number;
				target_node = crt_a;
			}
			crt_a = crt_a->next;
		}
		if (best_match_num == LONG_MAX)
			crt_b->target = find_smallest(*a);
		else
			crt_b->target = target_node;
		crt_b = crt_b->next;
	}
}

void	set_positions(t_stack **stack)
{
	t_stack	*current;
	int		i;
	int		median;

	if (!(*stack))
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	current = *stack;
	while (current)
	{
		current->pos = i;
		current->below_median = true;
		if (current->pos > median)
			current->below_median = false;
		i++;
		current = current->next;
	}
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calc_cost(t_stack **a, t_stack **b)
{
	t_stack	*crt_b;
	int		len_a;
	int		len_b;

	if (!(*a) || !(*b))
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	crt_b = *b;
	while (crt_b)
	{
		crt_b->push_cost = crt_b->pos;
		if (crt_b->below_median == false)
			crt_b->push_cost = len_b - crt_b->pos;
		if (crt_b->target->below_median)
			crt_b->target->push_cost = crt_b->target->pos;
		else
			crt_b->target->push_cost = len_a - crt_b->target->pos;
		if ((crt_b->below_median && crt_b->target->below_median)
			|| (!crt_b->below_median && !crt_b->target->below_median))
			crt_b->push_cost = max(crt_b->push_cost, crt_b->target->push_cost);
		else
			crt_b->push_cost += crt_b->target->push_cost;
		crt_b = crt_b->next;
	}
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest_node;
	int		cheapest_push_cost;

	if (!b)
		return (NULL);
	cheapest_node = b;
	cheapest_push_cost = INT_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_push_cost)
		{
			cheapest_node = b;
			cheapest_push_cost = b->push_cost;
		}
		b = b->next;
	}
	return (cheapest_node);
}
