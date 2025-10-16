/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:03:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/16 14:57:18 by ilaliev          ###   ########.fr       */
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

static void	sleep_philo(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	usleep(philo->data->rules.tts * 1000);
}

static void	eat(t_philo *philo, uint32_t left_fork, uint32_t right_fork)
{
	if (left_fork == right_fork)
	{
		usleep(philo->data->rules.ttl * 1000);
		return ;
	}
	pthread_mutex_lock(&philo->data->forks[left_fork]);
	pthread_mutex_lock(&philo->data->forks[right_fork]);
	safe_print(philo, "has taken a fork");
	safe_print(philo, "has taken a fork");
	philo->last_meal_time = safe_print(philo, "is eating");
	philo->meals_eaten++;
	if (philo->meals_eaten >= philo->data->rules.max_eat)
		philo->done_eating = true;
	usleep(philo->data->rules.tte * 1000);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
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
	while (!is_dead(philo->data))
	{
		safe_print(philo, "is thinking");
		eat(philo, left_fork, right_fork);
		sleep_philo(philo);
	}
	if (philo->done_eating == true)
		usleep(10000000);
	return (NULL);
}

void	check_end(t_data *data)
{
	uint32_t	i;

	i = 0;
	while (i < data->rules.philos)
	{
		if (data->philos->done_eating == false)
			return ;
		else
			i++;
	}
	done_eating(data);		//todo
}

void	*monitor_routine(void *arg)
{
	t_data		*data;
	uint32_t	i;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		i = 0;
		check_end(data);
		while (i < data->rules.philos)
		{
			if (get_time() - data->philos[i].last_meal_time > data->rules.ttl
				&& data->philos->done_eating == false)
			{
				pthread_mutex_lock(&data->rules.death_mutex);
				data->rules.someone_died = true;
				pthread_mutex_unlock(&data->rules.death_mutex);
				death_print(&data->philos[i], "died");
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
