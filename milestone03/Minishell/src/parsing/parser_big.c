/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 01:13:21 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:13:44 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_parser	init_parser(char *input, t_env_list *env_list,
			int last_exit_status)
{
	t_parser	parser;

	parser.tokens = tokenize(input);
	parser.current = parser.tokens;
	parser.env_list = env_list;
	parser.last_exit_status = last_exit_status;
	return (parser);
}

static t_cmd_list	*parse_commands(t_parser *parser)
{
	t_cmd_list	*cmd_list;
	t_cmd_node	*cmd;

	cmd_list = init_cmd_list(parser->env_list);
	while (parser->current && parser->current->type != TOKEN_EOF)
	{
		cmd = parse_command(parser);
		if (cmd)
			add_cmd_node(cmd_list, cmd);
		if (parser->current && parser->current->type == TOKEN_PIPE)
			advance(parser);
	}
	return (cmd_list);
}

t_cmd_list	*parse_input(char *input, t_env_list *env_list,
			int last_exit_status)
{
	t_parser	parser;
	t_cmd_list	*cmd_list;

	if (has_unclosed_quote(input))
		return (NULL);
	parser = init_parser(input, env_list, last_exit_status);
	if (!validate_syntax(parser.tokens))
	{
		free_tokens(parser.tokens);
		return (NULL);
	}
	cmd_list = parse_commands(&parser);
	free_tokens(parser.tokens);
	return (cmd_list);
}
