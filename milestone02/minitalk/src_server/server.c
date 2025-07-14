/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:47:14 by ilaliev           #+#    #+#             */
/*   Updated: 2025/07/14 17:13:09 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_sig(int sig)
{
	static int				bits = 8;
	static unsigned char	current_char = 0;
	char					temp;

	temp = 2;
	if (sig == SIGUSR1)
		temp = 1;
	else if (sig == SIGUSR2)
		temp = 0;
	if (temp == 2)
		return ;
	current_char = current_char | temp;
	bits--;
	if (bits > 0)
		current_char = current_char << 1;
	if (bits < 0)
	{
		if (current_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		current_char = 0;
		bits = 7;
	}
}

int	main(void)
{
	int					pid;
	
	pid = (int)getpid();
	ft_printf("My PID: %d\n", pid);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (0);
}
