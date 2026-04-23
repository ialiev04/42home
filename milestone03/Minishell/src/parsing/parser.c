/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuerliu <yuerliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:51:52 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/10 21:45:59 by yuerliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**parse_command_args(t_parser *parser, t_file_list *files)
{
	t_token	**args;
	int		count;
	char	**result;

	args = malloc(sizeof(t_token *) * (count_args(parser->current) + 1));
	count = 0;
	while (parser->current && parser->current->type == TOKEN_WORD)
	{
		args[count++] = parser->current;
		advance(parser);
		while (parser->current && (parser->current->type == TOKEN_REDIR_IN
				|| parser->current->type == TOKEN_REDIR_OUT
				|| parser->current->type == TOKEN_REDIR_APPEND
				|| parser->current->type == TOKEN_REDIR_HEREDOC))
			if (!parse_single_redirect(parser, files))
				return (free(args), NULL);
	}
	result = build_args_array(args, count, parser);
	free(args);
	return (result);
}

static int	parse_leading_redirects(t_parser *parser, t_file_list *files)
{
	while (parser->current && (parser->current->type == TOKEN_REDIR_IN
			|| parser->current->type == TOKEN_REDIR_OUT
			|| parser->current->type == TOKEN_REDIR_APPEND
			|| parser->current->type == TOKEN_REDIR_HEREDOC))
		if (!parse_single_redirect(parser, files))
			return (0);
	return (1);
}

t_cmd_node	*parse_command(t_parser *parser)
{
	t_cmd_node	*cmd;
	t_file_list	*files;

	if (!parser->current || parser->current->type == TOKEN_EOF
		|| parser->current->type == TOKEN_PIPE)
		return (NULL);
	cmd = create_cmd_node();
	files = malloc(sizeof(t_file_list));
	files->head = NULL;
	files->tail = NULL;
	files->size = 0;
	if (!parse_leading_redirects(parser, files))
		return (NULL);
	cmd->cmd = parse_command_args(parser, files);
	cmd->files = files;
	if (is_builtin(cmd->cmd[0]))
		cmd->cmd_type = BUILTIN;
	else
		cmd->cmd_type = CMD;
	return (cmd);
}

t_cmd_list	*init_cmd_list(t_env_list *env_list)
{
	t_cmd_list	*cmd_list;

	cmd_list = malloc(sizeof(t_cmd_list));
	if (!cmd_list)
		return (NULL);
	cmd_list->head = NULL;
	cmd_list->tail = NULL;
	cmd_list->size = 0;
	cmd_list->env_list = env_list;
	return (cmd_list);
}
