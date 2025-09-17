/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:27 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/17 21:01:57 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_rules	*rules;

	if (ac == 5 || ac == 6)
	{
		check_syntax(ac, av);
		init(ac, av, &philo, rules);
		edge_case(philo, rules);
		init_threads(&philo, rules);
		join_threads(&philo, rules);
	}
	else
		return(error_msg());
}
