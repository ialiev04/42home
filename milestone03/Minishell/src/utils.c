/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:53:23 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/08 04:15:42 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern volatile sig_atomic_t	g_signal_status;

void	empty_error(int *last_exit_status, t_env_list *env_list)
{
	free(last_exit_status);
	free_env_list(env_list);
	exit(2);
}

void	malexit(t_env_list *env_list)
{
	free_env_list(env_list);
	exit(2);
}

void	status_handler(int *last_exit_status)
{
	if (g_signal_status != 0)
	{
		*last_exit_status = g_signal_status;
		g_signal_status = 0;
	}
	if (*last_exit_status == 131)
		*last_exit_status = 130;
}

int	isempty(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_isprint((int)input[i]))
			return (1);
		i++;
	}
	return (0);
}
