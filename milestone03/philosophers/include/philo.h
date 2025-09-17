/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:29 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/17 21:02:47 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>


typedef struct	s_rules
{
	uint32_t	philos;
	uint32_t	ttl;
	uint32_t	tte;
	uint32_t	tts;
	uint32_t	max_eat;
	int			start_time;		//false, need something else
}	t_rules;

typedef struct s_philo
{
	pthread_t	thread_id;
	uint32_t	num;
	bool		eating;
	bool		sleeping;
	bool		thinking;
	t_fork		*next_fork;
	t_fork		*prev_fork;
	t_philo 	*next;
	t_philo		*prev;
	t_rules		*rules;
}	t_philo;

typedef struct s_fork
{
	bool	status;
	t_philo	*prev;
	t_philo	*next;
}	t_fork;

uint32_t	ft_atoi(const char *s);
void		check_syntax(int ac, char **av);
void		init(int ac, char **av, t_philo **philo, t_rules *rules);
void		edge_case(t_philo *philo, t_rules *rules);
void		init_threads(t_philo **philo, t_rules *rules);
void		join_threads(t_philo **philo, t_rules *rules);

#endif