/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:38:33 by ilaliev           #+#    #+#             */
/*   Updated: 2025/10/16 14:57:27 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	done_eating(t_data	*data)
{
	clean_exit()
}

void	clean_exit(int error)
{
	exit(error);
}

int	error_msg(void)
{
	printf("*************************************************************");
	printf("*******************************************\n");
	printf("Wrong syntax! Please enter:\n");
	printf("	./philo <number_of_philosophers> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> (<number_of_meals>)\n");
	printf("unsigned integers only\n");
	printf("*************************************************************");
	printf("*******************************************\n");
	return (1);
}
