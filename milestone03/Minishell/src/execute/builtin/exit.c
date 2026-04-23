/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:30 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:47:31 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_exit(t_cmd_node *cmd_node, int *last_exit_status)
{
	int	exit_code;

	exit_code = 0;
	if (isatty(STDIN_FILENO))
		ft_putstr_fd("exit\n", 1);
	if (!cmd_node || !cmd_node->cmd)
		exit(exit_code);
	if (cmd_node->cmd[1])
	{
		if (!is_valid_number(cmd_node->cmd[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(cmd_node->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(2);
		}
		exit_code = ft_atoi(cmd_node->cmd[1]);
		if (cmd_node->cmd[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			*last_exit_status = 1;
			return ;
		}
	}
	exit(exit_code);
}
