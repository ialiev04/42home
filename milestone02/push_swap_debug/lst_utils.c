/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:50:25 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/30 15:31:37 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
