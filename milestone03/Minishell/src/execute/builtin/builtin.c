/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 05:47:13 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:10:32 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static void	check_bi(t_cmd_node *node, t_env_list *env_list,
		int *last_exit_status)
{
	if (ft_strncmp(node->cmd[0], "cd", 3) == 0)
	{
		if (builtin_cd(node, env_list, last_exit_status) == 1)
			*last_exit_status = 1;
	}
	else if (ft_strncmp(node->cmd[0], "echo", 5) == 0)
		builtin_echo(node, last_exit_status);
	else if (ft_strncmp(node->cmd[0], "env", 4) == 0)
		builtin_env(env_list, last_exit_status);
	else if (ft_strncmp(node->cmd[0], "exit", 5) == 0)
		builtin_exit(node, last_exit_status);
	else if (ft_strncmp(node->cmd[0], "export", 7) == 0)
		builtin_export(node, env_list, last_exit_status);
	else if (ft_strncmp(node->cmd[0], "pwd", 4) == 0)
		builtin_pwd(last_exit_status);
	else if (ft_strncmp(node->cmd[0], "unset", 6) == 0)
		builtin_unset(node, env_list, last_exit_status);
}

int	check_what_builtin(t_cmd_node *node, t_env_list *env_list,
		int *last_exit_status)
{
	int	saved_stdin;
	int	saved_stdout;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	if (setup_redir(node) == -1)
	{
		*last_exit_status = 1;
		return (-1);
	}
	check_bi(node, env_list, last_exit_status);
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	return (0);
}
