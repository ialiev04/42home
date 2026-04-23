/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:18 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 05:47:19 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static int	is_flag_echo(char *flag)
{
	int		i;

	if (!flag || flag[0] != '-')
		return (0);
	i = 1;
	if (!flag[i])
		return (0);
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	builtin_echo(t_cmd_node *cmd_node, int *last_exit_status)
{
	int	is_flag;
	int	i;
	int	print_space;

	is_flag = is_flag_echo(cmd_node->cmd[1]);
	i = 1;
	print_space = 0;
	if (is_flag == 1)
	{
		while (cmd_node->cmd[i] && is_flag_echo(cmd_node->cmd[i]))
			i++;
	}
	while (cmd_node->cmd[i])
	{
		if (print_space)
			ft_putstr_fd(" ", STDOUT_FILENO);
		ft_putstr_fd(cmd_node->cmd[i], STDOUT_FILENO);
		print_space = 1;
		i++;
	}
	if (is_flag == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	*last_exit_status = 0;
}
