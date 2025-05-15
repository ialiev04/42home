/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/05/15 12:54:52 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_all(t_stack **a, char **av, int av_allocated)
{
	free_list(a);
	if (av_allocated == 1)
	{
		while (av)
		{
			free(*av);
			av++;
		}
	}
	exit(ft_printf("ERROR\n"));
}

int	error_code(int code)
{
	if (code == 0)
		ft_printf("	Error code 0:\n	invalid input");
	else if (code == 1)

	else if (code == 2)
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		av_allocated;

	a = NULL;
	b = NULL;
	av_allocated = 0;
	if (ac < 2 || (ac == 2 && !*av[1]))
		return (error_code(0));
	if (ac == 2)
		av = split(av[1], ' ', &av_allocated);
	if (stack_a(&a, av, ac) == 1)
		return (free_all(&a, av, av_allocated));
	if (stack_sorted(&a) == 1)
	{
		if (stack_len(a) == 2)
			sa(&a, false);					//todo 2nd
		else if (stack_len(a) == 3)
			sort_three(&a);			//todo 3rd
		else
			sort_stacks(&a, &b);		//todo 1st
	}
	free_all(&a, av, av_allocated);
	return (0);
}
