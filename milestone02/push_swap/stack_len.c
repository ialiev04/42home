/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:44:50 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/14 13:47:23 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack **a)
{
	int		len;
	t_stack	stack;

	len = 0;
	stack = *a;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
