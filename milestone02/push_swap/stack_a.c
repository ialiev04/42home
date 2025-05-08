/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:44:16 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/08 14:46:51 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (*str >= 0 && *str <= 9)
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * is_pos);
}

static void	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!a)
		return ;		//dont like
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;		//dont like
	node->next = NULL;
	node->number = n;
	if(!(*a))
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
}

void	stack_a(t_stack **a, char **av, int ac)
{
	int		i;
	long	num;

	i = 0;
	if (ac == 2 && ft_strncmp(*av, 'push_swap', 10)) //if ac == 2 no need, if ac > 2 av[0] == 'push_swap', maybe renew name
		i++;
	while(av[i])
	{
		if (check_syntax(av[i]))		//todo
			free_error();				//todo
		num = ft_atol(av[i]);			
		if (num > INT_MAX || num < INT_MIN)
			free_error();
		if(no_duplicates(a[0]))				//todo
			free_error();
		add_node(a, (int)num);
		i++;
	}
}
