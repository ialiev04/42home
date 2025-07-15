/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:13:03 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/16 01:00:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_syntax(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
		if (av[j][i] <= '9' && av[j][i] >= '0')
			i++;
		else
			return (error_msg());
		j++;
	}
}

void	init_philo(int ac, char **av, t_philo *philo, t_rules *rules)
{
	rules->philos = ft_atoi(av[1]);
	rules->ttl = ft_atoi(av[2]);
	rules->tte = ft_atoi(av[3]);
	rules->tts = ft_atoi(av[4]);
	if (ac == 6)
		rules->max_eat = ft_atoi(av[5]);
}
