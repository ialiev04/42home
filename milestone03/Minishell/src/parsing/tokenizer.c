/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:52:37 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:54:40 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_operator_type(char *input, int *i, t_token_type *type)
{
	if (input[*i] == '|')
		*type = TOKEN_PIPE;
	else if (input[*i] == '<' && input[*i + 1] == '<')
		*type = TOKEN_REDIR_HEREDOC;
	else if (input[*i] == '>' && input[*i + 1] == '>')
		*type = TOKEN_REDIR_APPEND;
	else if (input[*i] == '<')
		*type = TOKEN_REDIR_IN;
	else
		*type = TOKEN_REDIR_OUT;
}

static char	*get_operator_value(char *input, int *i)
{
	if (input[*i] == '|')
	{
		(*i)++;
		return (ft_strdup("|"));
	}
	if (input[*i] == '<' && input[*i + 1] == '<')
	{
		(*i) += 2;
		return (ft_strdup("<<"));
	}
	if (input[*i] == '>' && input[*i + 1] == '>')
	{
		(*i) += 2;
		return (ft_strdup(">>"));
	}
	if (input[*i] == '<')
	{
		(*i)++;
		return (ft_strdup("<"));
	}
	(*i)++;
	return (ft_strdup(">"));
}

static t_token	*create_operator_token(char *input, int *i)
{
	t_token_type	type;
	char			*value;

	set_operator_type(input, i, &type);
	value = get_operator_value(input, i);
	return (create_token(type, value));
}

static t_token	*create_word_token(char *input, int *i)
{
	int		len;
	char	*value;

	len = get_word_len(input, *i);
	value = ft_substr(input, *i, len);
	*i += len;
	return (create_token(TOKEN_WORD, value));
}

t_token	*tokenize(char *input)
{
	t_token	*head;
	t_token	*new_token;
	int		i;

	head = NULL;
	i = 0;
	while (input[i])
	{
		i = skip_whitespace(input, i);
		if (!input[i])
			break ;
		if (is_special_char(input[i]))
			new_token = create_operator_token(input, &i);
		else
			new_token = create_word_token(input, &i);
		add_token(&head, new_token);
	}
	add_token(&head, create_token(TOKEN_EOF, NULL));
	return (head);
}
