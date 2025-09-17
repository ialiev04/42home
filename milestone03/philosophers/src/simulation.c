/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:03:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/17 21:20:55 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *philo_routine(void *arg)
{
	// logic for routine
}

void	join_threads(t_philo **philo, t_rules *rules)
{
	t_philo		*current_philo;
	uint32_t	i;

	current_philo = *philo;
	i = 0;
	while (i < rules->philos)
	{
		if (pthread_join(current_philo->thread_id, NULL))
			clean_exit();
		current_philo = current_philo->next;
		i++;
	}
}

void	init_threads(t_philo **philo, t_rules *rules)
{
	t_philo		*current_philo;
	uint32_t	i;

	current_philo = *philo;
	i = 0;
	while(i < rules->philos)
	{
		current_philo->rules = rules;
		if (pthread_create(&current_philo->thread_id, NULL, philo_routine, current_philo))
			clean_exit();
		current_philo = current_philo->next;
		i++;
	}
}