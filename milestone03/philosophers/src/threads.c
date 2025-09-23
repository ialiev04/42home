/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:27:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/23 17:15:10 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	join_threads(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->rules.philos)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			clean_exit(1);
		i++;
	}
	if (pthread_join(data->monitor_thread, NULL) != 0)
		clean_exit(1);
}

void	init_threads(t_data *data)
{
	uint32_t	i;

	data->rules.start_time = get_time();
	i = 0;
	while (i < data->rules.philos)
	{
		data->philos[i].last_meal_time = data->rules.start_time;
		if (pthread_create(&data->philos[i].thread_id, NULL,
				philo_routine, &data->philos[i]) != 0)
			clean_exit(1);
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
		clean_exit(1);
}

