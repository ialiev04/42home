/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/08/09 13:40:06 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	free_all(t_stack **a, char **av, int ac, bool error)
{
	char	**tmp;

	free_list(a);
	if (ac == 2)
	{
		tmp = av;
		while (*av)
		{
			free(*av);
			av++;
		}
		free(tmp);
	}
	if (error == true)
	{
		fprintf(stderr, "Error\n");
		exit(fprintf(stderr, "Error\n"));
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if ((ac == 2 && !*av[1]))
		return (fprintf(stderr, "Error\n"));
	if (ac == 2)
		av = split(av[1], ' ');
	if (stack_a(&a, av, ac) == 1)
		free_all(&a, av, ac, true);
	if (stack_sorted(&a) == 1)
	{
		if (stack_len(&a) == 2)
			sa(&a);
		else if (stack_len(&a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_all(&a, av, ac, false);
	return (0);
}
