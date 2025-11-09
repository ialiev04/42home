/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:13:03 by ilaliev           #+#    #+#             */
/*   Updated: 2025/11/09 17:14:20 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_rules(int ac, char **av, t_data *data)
{
	data->rules.philos = ft_atoi(av[1]);
	data->rules.ttl = ft_atoi(av[2]);
	data->rules.tte = ft_atoi(av[3]);
	data->rules.tts = ft_atoi(av[4]);
	if (ac == 6)
		data->rules.max_eat = ft_atoi(av[5]);
	else
		data->rules.max_eat = UINT32_MAX;
	data->rules.someone_died = false;
	if (pthread_mutex_init(&data->rules.print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->rules.death_mutex, NULL) != 0)
		return (error_exit(data, 1));
	if (pthread_mutex_init(&data->rules.data_mutex, NULL) != 0)
		return (error_exit(data, 2));
	if (edge_case(data) == 0)
		return (0);
	return (1);
}

static int	init_forks(t_data *data)
{
	uint32_t	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->rules.philos);
	if (data->forks == NULL)
		return (error_exit(data, 3));
	i = 0;
	while (i < data->rules.philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free_forks(data, i - 1);
			return (error_exit(data, 4));
		}
		i++;
	}
	return (1);
}

static int	init_philos(t_data *data)
{
	uint32_t	i;

	data->philos = malloc(sizeof(t_philo) * data->rules.philos);
	if (data->philos == NULL)
		return (error_exit(data, 4));
	i = 0;
	while (i < data->rules.philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->philos[i].done_eating = false;
		i++;
	}
	return (1);
}

int	init(int ac, char **av, t_data *data)
{
	if (init_rules(ac, av, data) == 0)
		return (0);
	if (init_forks(data) == 0)
		return (0);
	if (init_philos(data) == 0)
		return (0);
	return (1);
}
