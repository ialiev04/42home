/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:40 by ilaliev           #+#    #+#             */
/*   Updated: 2025/04/29 17:07:50 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_code(int code)
{
	if (code == 0)
		ft_printf("Error code 0:\n	invalid input");
	else if (code == 1)
	else if (code == 2)
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !*av[1]))
		return (error_code(0));
	if (ac == 2)
		split(av[1]); //todo
}
