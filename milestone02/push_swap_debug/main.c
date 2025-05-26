/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/22 19:46:25 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **a, char **av, int ac, bool error) //changed
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
	if (error == true)
		exit(1);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !*av[1]))
		return (ft_printf("Error 1\n"));
	if (ac == 2)
		av = split(av[1], ' ');
	if (stack_a(&a, av, ac) == 1)
	{
		ft_printf("stack_a");
		free_all(&a, av, ac, true);
	}
	if (stack_sorted(&a) == 1)
	{
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	ft_printf("got through all");
	free_all(&a, av, ac, false);
	return (0);
}
