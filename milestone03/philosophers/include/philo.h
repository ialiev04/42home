/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:29 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/16 14:15:16 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
void		check_syntax(int ac, char **av);
void		init(int ac, char **av, t_data *data);
void		edge_case(t_data *data);
void		init_threads(t_data *data);
void		join_threads(t_data *data);
int			error_msg(void);
void		clean_exit(int error);
uint64_t	get_time(void);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
uint64_t	safe_print(t_philo *philo, char *message);
void		death_print(t_philo *philo, char *message);
bool		is_dead(t_data *data);
void		check_end(t_data *data);

#endif