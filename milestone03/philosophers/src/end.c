/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:12:58 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/27 20:06:49 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	clean_exit(t_data *data)
{
	int		i;

	i = 0;
	free(data->philos);
	while (i < (int)data->rules.philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->rules.print_mutex);
	pthread_mutex_destroy(&data->rules.death_mutex);
	return (0);
}

int	error_exit(t_data *data, int i)
{
	if (i >= 1)
		pthread_mutex_destroy(&data->rules.print_mutex);
	if (i >= 2)
		pthread_mutex_destroy(&data->rules.death_mutex);
	if (i >= 3)
		free_forks(data, data->rules.philos - 1);
	if (i >= 4)
		free(data->philos);
	printf("something went wrong...\n");
	return (1);
}

int	error_msg(void)
{
	printf("*************************************************************");
	printf("*******************************************\n");
	printf("Wrong syntax! Please enter:\n");
	printf("\t./philo <number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> (<number_of_meals>)\n");
	printf("unsigned integers only\n");
	printf("*************************************************************");
	printf("*******************************************\n");
	return (1);
}
