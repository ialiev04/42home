/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:44:26 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/14 13:40:02 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack	**a)
{
	t_stack *current;
	t_stack	*next;
	
	current = *a;
	next = current->next;
	while (current)
	{
		if (current->number > next->number)
			return (1);
		current = next;
		next = current->next;
	}
	return (0);
}
