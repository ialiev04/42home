/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:20:01 by ilaliev           #+#    #+#             */
/*   Updated: 2025/06/16 21:08:31 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_biggest(t_stack *a)
{
	t_stack	*biggest;

	biggest = a;
	while (a)
	{
		if (biggest->number < a->number)
			biggest = a;
		a = a->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	while (a)
	{
		if (smallest->number > a->number)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
