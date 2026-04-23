/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:32:04 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/08 04:15:24 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern volatile sig_atomic_t	g_signal_status;

static void	process_input_line(char *input, t_env_list *env_list,
		int *last_exit_status)
{
	t_cmd_list	*cmd_list;

	cmd_list = parse_input(input, env_list, *last_exit_status);
	if (!cmd_list)
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		*last_exit_status = 2;
		return ;
	}
	heredoc_setup(cmd_list);
	if (g_signal_status != 0)
	{
		if (g_signal_status == -1)
			g_signal_status = 0;
		*last_exit_status = g_signal_status;
		free_cmd_list(cmd_list);
		return ;
	}
	handle_signals_main();
	process(cmd_list, last_exit_status, input);
	free_cmd_list(cmd_list);
}

void	shell_loop(t_env_list *env_list, int is_tty)
{
	char	*input;
	int		*last_exit_status;

	last_exit_status = malloc(sizeof(int));
	if (!last_exit_status)
		malexit(env_list);
	*last_exit_status = 0;
	g_signal_status = 0;
	while (1)
	{
		handle_signals_main();
		input = get_input(is_tty);
		status_handler(last_exit_status);
		if (handle_empty_input(input))
		{
			if (!input)
				break ;
			continue ;
		}
		add_history(input);
		g_signal_status = 0;
		process_input_line(input, env_list, last_exit_status);
		free(input);
	}
	free(last_exit_status);
}

int	*non_interactice_shell(t_env_list *env_list)
{
	char	*input;
	int		*last_exit_status;

	last_exit_status = malloc(sizeof(int));
	if (!last_exit_status)
	{
		free_env_list(env_list);
		exit(2);
	}
	*last_exit_status = 0;
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (!isempty(input))
			continue ;
		if (input[0] != '\0' && input[ft_strlen(input) - 1] == '\n')
			input[ft_strlen(input) - 1] = '\0';
		if (handle_empty_input(input))
			empty_error(last_exit_status, env_list);
		process_input_line(input, env_list, last_exit_status);
		free(input);
	}
	return (last_exit_status);
}
