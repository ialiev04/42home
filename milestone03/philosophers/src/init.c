/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:13:03 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/17 20:45:28 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_rules(int ac, char **av, t_philo *philo, t_rules *rules)
{
	rules->philos = ft_atoi(av[1]);
	rules->ttl = ft_atoi(av[2]);
	rules->tte = ft_atoi(av[3]);
	rules->tts = ft_atoi(av[4]);
	if (ac == 6)
		rules->max_eat = ft_atoi(av[5]);
	else
		rules->max_eat = UINT32_MAX;
	gettimeofday()		//todo
}

static void	init_philo(int ac, char **av, t_philo **philo, t_rules *rules)
{
	uint32_t	current_num;
	t_philo		*first_philo;
	t_philo		*current_philo;
	t_philo		*next_philo;

	first_philo = malloc(sizeof(t_philo));
	if (first_philo == NULL)
		clean_exit();		//todo
	first_philo->num = 1;
	current_philo = first_philo;
	current_num = 2;
	while (current_num <= rules->philos)
	{
		next_philo = malloc(sizeof(t_philo));
		if (next_philo == NULL)
			clean_exit();
		next_philo->num = current_num;
		current_philo->next = next_philo;
		next_philo->prev = current_philo;
		current_philo = next_philo;
		current_num++;
	}
	current_philo->next = first_philo;
	first_philo->prev = current_philo;
	*philo = first_philo;
}

static void	init_fork(int ac, char **av, t_philo **philo, t_rules *rules)
{
	uint32_t	i;
	t_philo		*current_philo;
	t_fork		*current_fork;

	current_philo = *philo;
	i = 0;
	while (i < rules->philos)
	{
		current_fork = malloc(sizeof(t_fork));
		if (current_fork == NULL)
			clean_exit();
		current_fork->status = true;
		current_fork->prev = current_philo;
		current_fork->next = current_philo->next;
		current_philo->next_fork = current_fork;
		current_philo->next->prev_fork = current_fork;
		i++;
	}
}

void	init(int ac, char **av, t_philo **philo, t_rules *rules)
{
	init_rules(ac, av, philo, rules);
	init_philo(ac, av, philo, rules);
	init_forks(ac, av, philo, rules);
}
