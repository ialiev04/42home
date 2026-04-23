/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:46:54 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 00:48:22 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*advance(t_parser *parser)
{
	if (parser->current && parser->current->type != TOKEN_EOF)
		parser->current = parser->current->next;
	return (parser->current);
}

int	parse_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		return (INFILE);
	if (type == TOKEN_REDIR_OUT)
		return (OUTFILE);
	if (type == TOKEN_REDIR_APPEND)
		return (APPEND);
	if (type == TOKEN_REDIR_HEREDOC)
		return (HERE_DOC);
	return (-1);
}

int	parse_single_redirect(t_parser *parser, t_file_list *files)
{
	int			redir_type;
	char		*filename;
	t_file_node	*file_node;

	redir_type = parse_redir_type(parser->current->type);
	if (redir_type == -1)
		return (0);
	advance(parser);
	if (!parser->current || parser->current->type != TOKEN_WORD)
		return (0);
	filename = expand_variables(parser->current->value, parser->env_list,
			parser->last_exit_status);
	file_node = create_file_node(filename, redir_type);
	add_file_node(files, file_node);
	advance(parser);
	return (1);
}

char	**build_args_array(t_token **args, int count, t_parser *parser)
{
	char	**result;
	int		i;

	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = expand_variables(args[i]->value, parser->env_list,
				parser->last_exit_status);
		i++;
	}
	result[count] = NULL;
	return (result);
}

int	count_args(t_token *current)
{
	int		count;
	t_token	*tmp;

	count = 0;
	tmp = current;
	while (tmp && tmp->type == TOKEN_WORD)
	{
		count++;
		tmp = tmp->next;
		while (tmp && (tmp->type == TOKEN_REDIR_IN
				|| tmp->type == TOKEN_REDIR_OUT
				|| tmp->type == TOKEN_REDIR_APPEND
				|| tmp->type == TOKEN_REDIR_HEREDOC))
		{
			tmp = tmp->next;
			if (tmp)
				tmp = tmp->next;
		}
	}
	return (count);
}
