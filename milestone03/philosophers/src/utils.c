/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:16:51 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/23 08:29:11 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <inttypes.h>

unsigned int	ft_atoi(const char *s)
{
	size_t		i;
	uint64_t	ret;

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
		error_exit(1); // todo
	return ((uint32_t)ret);
}

int	edge_case(t_data	*data)
{
	if (data->rules.max_eat == 0)
		return (0);
	return (1);
}

int	check_syntax(int ac, char **av)
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
			return (error_msg());
		j++;
	}
	return (0);
}

void	death_print(t_philo *philo)
{
	uint64_t	timestamp;

	timestamp = get_time() - philo->data->rules.start_time;
	pthread_mutex_lock(&philo->data->rules.print_mutex);
	printf("%llu %d has died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->rules.print_mutex);
}
