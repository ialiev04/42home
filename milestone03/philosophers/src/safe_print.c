/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:35:43 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/23 11:24:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	think_print(t_philo *philo)
{
	uint64_t	start;
	
	if (is_dead(philo->data) == false)
	{
		pthread_mutex_lock(&philo->data->rules.print_mutex);
		start = philo->data->rules.start_time;
		printf("%llu %d is thinking\n", get_time() - start, philo->id);
		pthread_mutex_unlock(&philo->data->rules.print_mutex);
	}
}

void	sleep_print(t_philo *philo)
{
	uint64_t	start;
	
	if (is_dead(philo->data) == false)
	{
		pthread_mutex_lock(&philo->data->rules.print_mutex);
		start = philo->data->rules.start_time;
		printf("%llu %d is sleeping\n", get_time() - start, philo->id);
		pthread_mutex_unlock(&philo->data->rules.print_mutex);
	}
}

uint64_t	eat_print(t_philo *philo)
{
	uint64_t	timestamp;
	uint64_t	time;

	time = 0;
	if (is_dead(philo->data) == false)
	{
		pthread_mutex_lock(&philo->data->rules.print_mutex);
		time = get_time();
		timestamp = time - philo->data->rules.start_time;
		printf("%llu %d has taken a fork\n", timestamp, philo->id);
		printf("%llu %d has taken a fork\n", timestamp, philo->id);
		printf("%llu %d is eating\n", timestamp, philo->id);
		pthread_mutex_unlock(&philo->data->rules.print_mutex);
	}
	return (time);
}
