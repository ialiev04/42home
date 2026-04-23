/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:31:05 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 07:48:52 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env_list	*env_list;
	int			is_tty;
	int			*last_exit_status;
	int			final_status;

	(void)argc;
	(void)argv;
	is_tty = isatty(STDIN_FILENO);
	env_list = init_env_list(envp);
	if (!env_list)
		return (1);
	if (is_tty)
		shell_loop(env_list, is_tty);
	else
	{
		last_exit_status = non_interactice_shell(env_list);
		final_status = *last_exit_status;
		free(last_exit_status);
		free_env_list(env_list);
		return (final_status);
	}
	free_env_list(env_list);
	return (0);
}
