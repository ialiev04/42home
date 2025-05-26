/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:44:16 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/22 19:04:54 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '\0')
		return (0);
	else
		return (1);
}

long	ft_atol(char *str)
{
	long	ret;
	int		is_pos;

	ret = 0;
	is_pos = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_pos = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * is_pos);
}

static int	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return (1);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (1);
	node->next = NULL;
	node->number = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = last_node(*a);
		last->next = node;
		node->prev = last;
	}
	return (0);
}

int	stack_a(t_stack **a, char **av, int ac)
{
	int		i;
	long	num;

	i = 0;
	if (*av == NULL)
		return (1);
	if (ac > 2 && ft_strncmp(*av, "./push_swap", 12))
		i++;
	while (av[i])
	{
		if (check_syntax(av[i]) == 1)
			return (1);
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN || no_duplicates(*a, num) == 1)
			return (1);
		if (add_node(a, (int)num) == 1)
			return (1);
		i++;
	}
	return (0);
}
