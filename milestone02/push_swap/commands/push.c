/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:35:44 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/15 14:44:39 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*to_push;
	
	if (!src || !(*src))
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dst == NULL)
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst;
		to_push->next->prev = to_push;
		*dst = to_push; 
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	if (!(*a) || !a)
		return ;
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool checker)
{
	if (!(*b) || !b)
		return ;
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
