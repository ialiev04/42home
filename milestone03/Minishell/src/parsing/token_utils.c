/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:54:48 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:54:50 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_whitespace(char *input, int i)
{
	while (input[i] && is_whitespace(input[i]))
		i++;
	return (i);
}

int	get_word_len(char *input, int i)
{
	int		len;
	char	quote;

	len = 0;
	quote = 0;
	while (input[i + len])
	{
		if (quote)
		{
			if (input[i + len] == quote)
				quote = 0;
			len++;
		}
		else
		{
			if (input[i + len] == '\'' || input[i + len] == '"')
				quote = input[i + len];
			else if (is_whitespace(input[i + len])
				|| is_special_char(input[i + len]))
				break ;
			len++;
		}
	}
	return (len);
}

t_token	*create_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new_token)
{
	t_token	*current;

	if (!*head)
	{
		*head = new_token;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_token;
}

void	free_tokens(t_token *tokens)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->value);
		free(temp);
	}
}
