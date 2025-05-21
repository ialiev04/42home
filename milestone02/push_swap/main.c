/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/21 18:22:27 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_stack **a, char **av, int ac)
{
	free_list(a);
	if (ac == 2)
	{
		while (av)
		{
			free(*av);
			av++;
		}
	}
	ft_printf("Error\n");
	exit();
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av_allocated = 0;
	if (ac < 2 || (ac == 2 && !*av[1]))
		return (ft_printf("Error\n"));
	if (ac == 2)
		av = split(av[1], ' ');
	if (stack_a(&a, av, ac) == 1)
		return (free_all(&a, av, ac));
	if (stack_sorted(&a) == 1)
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_all(&a, av, ac);
	return (0);
}
