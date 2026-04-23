/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:22:28 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 06:43:35 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

volatile sig_atomic_t	g_signal_status = 0;

void	handle_signals_heredoc(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	struct sigaction	sigstop;

	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigemptyset(&sigstop.sa_mask);
	sigint.sa_handler = handle_sigint_heredoc;
	sigint.sa_flags = 0;
	sigquit.sa_handler = handle_sigquit_heredoc;
	sigquit.sa_flags = 0;
	sigstop.sa_handler = SIG_IGN;
	sigstop.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	sigaction(SIGTSTP, &sigstop, NULL);
}

void	handle_signals_main(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	struct sigaction	sigstop;

	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigemptyset(&sigstop.sa_mask);
	sigint.sa_handler = handle_sigint_main;
	sigint.sa_flags = 0;
	sigquit.sa_handler = SIG_IGN;
	sigquit.sa_flags = 0;
	sigstop.sa_handler = SIG_IGN;
	sigstop.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	sigaction(SIGTSTP, &sigstop, NULL);
}

void	mute_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;
	struct sigaction	sigstop;

	sigemptyset(&sigint.sa_mask);
	sigemptyset(&sigquit.sa_mask);
	sigemptyset(&sigstop.sa_mask);
	sigint.sa_handler = SIG_IGN;
	sigint.sa_flags = 0;
	sigquit.sa_handler = SIG_IGN;
	sigquit.sa_flags = 0;
	sigstop.sa_handler = SIG_IGN;
	sigstop.sa_flags = 0;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	sigaction(SIGTSTP, &sigstop, NULL);
}
