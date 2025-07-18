/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:27 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/16 01:01:22 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*rules;

	if (ac == 5 || ac == 6)
	{
		if (check_syntax(ac, av) == 1);			//check sytax, exit if failure
			return (error_msg());
		init_philo(ac, av, philo, rules);		//initiate philo values
	}
	else
		return(error_msg());
}
