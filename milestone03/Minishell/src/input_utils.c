/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:16:37 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/07 07:30:26 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(int is_tty)
{
	char	*input;
	char	*more;

	input = NULL;
	if (is_tty)
	{
		input = readline("minishell$ ");
		while (input && has_unclosed_quote(input))
		{
			more = readline("> ");
			if (!more)
			{
				free(input);
				input = NULL;
				break ;
			}
		}
	}
	else
	{
		input = get_next_line(STDIN_FILENO);
		input = ft_strtrim(get_next_line(STDIN_FILENO), "\n");
	}
	return (input);
}

int	handle_empty_input(char *input)
{
	int	i;

	if (!input)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		return (1);
	}
	if (*input == '\0')
		return (free(input), 1);
	i = 0;
	while (input[i] && is_whitespace(input[i]))
		i++;
	if (!input[i])
		return (free(input), 1);
	return (0);
}
