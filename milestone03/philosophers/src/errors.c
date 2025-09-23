/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:38:33 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/22 16:38:59 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clean_exit(int error)
{
	exit(error);
}

int	error_msg(void)
{
	printf("*************************************************************\n");
	printf("Wrong syntax! Please enter:\n");
	printf("	./philo number_of_philosophers time_to_die\n");
	printf("			time_to_eat time_to_sleep\n");
	printf("	unsigned integers only\n");
	printf("*************************************************************\n");
	return (1);
}