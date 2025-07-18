/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:50:25 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 17:22:39 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*last_node(t_stack *first)
{
	t_stack	*ret;

	ret = first;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}

int	no_duplicates(t_stack *a, int num)
{
	while (a)
	{
		if (num == a->number)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_list(t_stack **a)
{
	t_stack	*next;
	t_stack	*current;

	current = *a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	rotate_till_done(t_stack **a)
{
	bool	rotate_up;
	t_stack	*smallest_num;

	rotate_up = false;
	smallest_num = find_smallest(*a);
	set_positions(a);
	if (smallest_num->below_median == true)
		rotate_up = true;
	while (stack_sorted(a) == 1)
	{
		if (rotate_up == false)
			rra(a);
		else
			ra(a);
	}
}
