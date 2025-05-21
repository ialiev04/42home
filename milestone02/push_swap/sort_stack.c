/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:45:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/21 19:46:53 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_taget_nodes(t_stack **a, t_stack **b)
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
			crt_b->target_node = find_smallest(a);
		else
			crt_b->target = target_node;
		crt_b = crt_b->next;
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{

}
