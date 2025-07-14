/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:47:36 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/14 17:11:41 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_char(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(60);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf("Usage: ./client <pid>, <message>\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	msg = av[2];
	i = 0;
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\0');
	return (0);
}
