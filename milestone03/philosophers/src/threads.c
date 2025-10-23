/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:27:47 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/22 16:47:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	join_threads(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->rules.philos)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			return (error_exit(1));
		i++;
	}
	if (pthread_join(data->monitor_thread, NULL) != 0)
		return (error_exit(1));
	
	return (1);
}

int	init_threads(t_data *data)
{
	uint32_t	i;

	i = 0;
	data->rules.start_time = get_time();
	while (i < data->rules.philos)
	{
		data->philos[i].last_meal_time = data->rules.start_time;
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor_routine, data) != 0)
		return (clean_exit(data));
	i = 0;
	while (i < data->rules.philos)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL,
				philo_routine, &data->philos[i]) != 0)
			return (clean_exit(data));
		i++;
	}
	return (1);
}
