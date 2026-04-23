/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:52:30 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:52:31 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	return (0);
}

int	has_unclosed_quote(const char *s)
{
	char	quote;

	quote = 0;
	while (*s)
	{
		if (!quote && (*s == '\'' || *s == '"'))
			quote = *s;
		else if (quote && *s == quote)
			quote = 0;
		s++;
	}
	return (quote != 0);
}

int	validate_syntax(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	if (current && current->type == TOKEN_PIPE)
		return (0);
	while (current && current->type != TOKEN_EOF)
	{
		if (current->type == TOKEN_PIPE)
		{
			if (!current->next || current->next->type == TOKEN_EOF
				|| current->next->type == TOKEN_PIPE)
				return (0);
		}
		if (current->type >= TOKEN_REDIR_IN
			&& current->type <= TOKEN_REDIR_HEREDOC)
		{
			if (!current->next || current->next->type != TOKEN_WORD)
				return (0);
		}
		current = current->next;
	}
	return (1);
}
