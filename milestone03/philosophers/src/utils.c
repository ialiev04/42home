/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:16:51 by ilaliev           #+#    #+#             */
/*   Updated: 2025/09/17 20:36:39 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
		clean_exit(1);
	return ((uint32_t)ret);
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

void	check_syntax(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (j < ac)
	{
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

void	edge_case(t_philo *philo, t_rules *rules)
{
	if (rules->max_eat == 0)
		clean_exit(0);
	else if (philo->num == philo->next->num)
		one_philo(philo, rules);			//todo
}

void	clean_exit(int error)
{
	
}