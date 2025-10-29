/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:29 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/29 16:41:40 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct s_rules
{
	uint32_t		philos;
	uint32_t		ttl;
	uint32_t		tte;
	uint32_t		tts;
	uint32_t		max_eat;
	uint64_t		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	bool			someone_died;
}	t_rules;

typedef struct s_philo
{
	pthread_t		thread_id;
	uint32_t		id;
	uint32_t		meals_eaten;
	uint64_t		last_meal_time;
	bool			done_eating;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		monitor_thread;
	t_rules			rules;
}	t_data;

uint32_t	ft_atoi(const char *s);
int			check_syntax(int ac, char **av);
int			init(int ac, char **av, t_data *data);
int			edge_case(t_data *data);
int			init_threads(t_data *data);
int			join_threads(t_data *data);
int			error_msg(void);
int			clean_exit(t_data *data);
uint64_t	get_time(void);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
uint64_t	eat_print(t_philo *philo);
void		death_print(t_philo *philo);
bool		is_dead(t_data *data);
int			check_end(t_data *data);
int			error_exit(t_data *data, int i);
void		think_print(t_philo *philo);
void		sleep_print(t_philo *philo);
void		free_forks(t_data *data, int forks);

#endif