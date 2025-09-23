/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:27 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/22 17:40:13 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		check_syntax(ac, av);
		init(ac, av, &data);
		edge_case(&data);
		init_threads(&data);
		join_threads(&data);
	}
	else
		return (error_msg());
}
