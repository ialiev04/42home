/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:13:03 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/16 13:07:40 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_rules(int ac, char **av, t_data *data)
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
		clean_exit(1);
	if (pthread_mutex_init(&data->rules.death_mutex, NULL) != 0)
		clean_exit(1);
	edge_case(data);
}

static void	init_forks(t_data *data)
{
	uint32_t	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->rules.philos);
	if (data->forks == NULL)
		clean_exit(1);
	i = 0;
	while (i < data->rules.philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			clean_exit(1);
		i++;
	}
}

static void	init_philos(t_data *data)
{
	uint32_t	i;

	data->philos = malloc(sizeof(t_philo) * data->rules.philos);
	if (data->philos == NULL)
		clean_exit(1);
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
}

void	init(int ac, char **av, t_data *data)
{
	init_rules(ac, av, data);
	init_forks(data);
	init_philos(data);
}
