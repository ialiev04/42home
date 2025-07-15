/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:16:51 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/16 01:00:55 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	positive;
	int	ret;

	i = 0;
	positive = 1;
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
	return (ret * positive);
}

int	error_msg(void)
{
	printf("*************************************************************\n");
	printf("Wrong syntax! Please enter:\n");
	printf("	./philo number_of_philosophers time_to_die\n");
	printf("			time_to_eat time_to_sleep\n");
	printf("*************************************************************\n");
	return (1);
}