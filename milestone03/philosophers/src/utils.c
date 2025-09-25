/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:16:51 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/25 17:34:20 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	ft_atoi(const char *s)
{
	size_t		i;
	uint32_t	ret;

	i = 0;
	ret = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + (s[i] - '0');
		i++;
	}
	if (ret > UINT32_MAX)
		clean_exit(1);
	return ((uint32_t)ret);
}

void	edge_case(t_data *data)
{
	if (data->rules.max_eat == 0 || data->rules.philos == 1)
		exit(0);
	else if (data->rules.philos == 1)
		exit(1); //one_philo()		//todo
}

void	check_syntax(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] == ' ' || av[j][i] == '	')
			i++;
		while (av[j][i] <= '9' && av[j][i] >= '0')
			i++;
		while (av[j][i] == ' ' || av[j][i] == '	')
			i++;
		if (av[j][i] != '\0')
			exit(error_msg());
		j++;
	}
}

uint64_t	get_time(void)
{
	struct timeval	tv;
	uint32_t		ms;

	gettimeofday(&tv, NULL);
	ms = (uint64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

uint64_t	safe_print(t_philo *philo, char *message)
{
	uint64_t	timestamp;

	timestamp = get_time();
	if (!is_dead(philo->data))
	{
		pthread_mutex_lock(&philo->data->rules.print_mutex);
		timestamp = get_time() - philo->data->rules.start_time;
		if (!philo->data->rules.someone_died)
			printf("%llu %d %s\n", timestamp, philo->id, message);
		pthread_mutex_unlock(&philo->data->rules.print_mutex);
	}
	return (timestamp);
}

void	death_print(t_philo *philo, char *message)
{
	uint64_t	timestamp;

	timestamp = get_time() - philo->data->rules.start_time;
	pthread_mutex_lock(&philo->data->rules.print_mutex);
	printf("%llu %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->data->rules.print_mutex);
}
