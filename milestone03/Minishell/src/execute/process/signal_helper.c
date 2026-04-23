/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:43:09 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:43:33 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	handle_sigint_main(int sig)
{
	(void)sig;
	g_signal_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_done = 1;
}

void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_signal_status = 131;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_done = 1;
}

void	handle_sigquit_heredoc(int sig)
{
	g_signal_status = -1;
	(void)sig;
	write(STDIN_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}
