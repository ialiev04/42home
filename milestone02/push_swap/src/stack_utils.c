/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:44:50 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/18 17:22:57 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack **a)
{
	int		len;
	t_stack	*stack;

	len = 0;
	stack = *a;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	stack_sorted(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	current = *a;
	while (current && current->next)
	{
		next = current->next;
		if (current->number > next->number)
			return (1);
		current = next;
	}
	return (0);
}
