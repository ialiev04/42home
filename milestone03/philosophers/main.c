/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:27 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/27 20:06:56 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (check_syntax(ac, av) != 0)
			return (1);
		if (init(ac, av, &data) == 0)
			return (1);
		if (edge_case(&data) == 0)
			return (error_exit(&data, 4));
		if (init_threads(&data) == 0)
			return (1);
		if (join_threads(&data) == 0)
			return (1);
	}
	else
		return (error_msg());
	return (clean_exit(&data));
}
