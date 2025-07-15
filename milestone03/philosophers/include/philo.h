/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:05:29 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/16 00:40:35 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>


typedef struct	s_rules
{
	unsigned int	philos;
	unsigned int	ttl;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	max_eat;
}	t_rules;


typedef struct s_philo
{
	int	num;
	t_philo *next;
	t_philo	*prev;
}	t_philo;

int		ft_atoi(const char *s);
int		check_syntax(int ac, char **av);
void	init_philo(int ac, char **av, t_philo *philo, t_philo *rules);

#endif