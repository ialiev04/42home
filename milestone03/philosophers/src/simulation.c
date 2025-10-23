/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:03:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/24 00:43:39 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_dead(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data->rules.death_mutex);
	result = data->rules.someone_died;
	pthread_mutex_unlock(&data->rules.death_mutex);
	return (result);
}

static void	eat(t_philo *philo, uint32_t left_fork, uint32_t right_fork)
{
	if (left_fork == right_fork)
	{
		usleep(philo->data->rules.ttl * 1000);
		return ;
	}
	if (philo->id % 2 == 1)
		usleep(2000);
	pthread_mutex_lock(&philo->data->forks[left_fork]);
	pthread_mutex_lock(&philo->data->forks[right_fork]);
	philo->last_meal_time = eat_print(philo);
	philo->meals_eaten++;
	if (philo->meals_eaten >= philo->data->rules.max_eat)
		philo->done_eating = true;
	usleep(philo->data->rules.tte * 1000);
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	uint32_t	left_fork;
	uint32_t	right_fork;

	philo = (t_philo *)arg;
	left_fork = philo->id - 1;
	right_fork = philo->id;
	if (philo->id == philo->data->rules.philos)
		right_fork = 0;
	// if (philo->id % 2 == 1)
	// {
	// 	uint32_t	tmp;
	// 	tmp = left_fork;
	// 	left_fork = right_fork;
	// 	right_fork = tmp;
	// }
	while (!is_dead(philo->data))
	{
		think_print(philo);
		eat(philo, left_fork, right_fork);
		if (philo->done_eating == true)
			return (NULL);
		sleep_print(philo);
		usleep(philo->data->rules.tts * 1000);
	}
	return (NULL);
}

int	check_end(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->rules.philos)
	{
		if (data->philos[i].done_eating == false)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data		*data;
	uint32_t	i;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		i = 0;
		if (check_end(data) == 1)
			break ;
		while (i < data->rules.philos)
		{
			if (get_time() - data->philos[i].last_meal_time > data->rules.ttl
				&& data->philos[i].done_eating == false)
			{
				pthread_mutex_lock(&data->rules.death_mutex);
				data->rules.someone_died = true;
				pthread_mutex_unlock(&data->rules.death_mutex);
				death_print(&data->philos[i]);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
