/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaliev <ilaliev@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 06:55:52 by ilaliev           #+#    #+#             */
/*   Updated: 2026/03/11 01:42:48 by ilaliev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	setup_redir(t_cmd_node *node)
{
	t_file_node	*current;

	if (node->files)
		current = node->files->head;
	else
		current = NULL;
	while (current != NULL)
	{
		if (check_redir(current) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}

int	check_redir(t_file_node *file_node)
{
	if (file_node->redir_type == INFILE || file_node->redir_type == HERE_DOC)
	{
		if (redir_infile(file_node) == -1)
			return (-1);
	}
	else if (file_node->redir_type == OUTFILE)
	{
		if (redir_outfile(file_node) == -1)
			return (-1);
	}
	else if (file_node->redir_type == APPEND)
	{
		if (redir_append(file_node) == -1)
			return (-1);
	}
	return (0);
}

char	*get_unique_name(void)
{
	static int	i = 0;
	char		*num_str;
	char		*full_path;

	while (1)
	{
		if (i < 0)
			return (NULL);
		num_str = ft_itoa(i);
		if (!num_str)
			return (NULL);
		full_path = ft_strjoin("/tmp/.heredoc_", num_str);
		free(num_str);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == -1)
			return (full_path);
		free(full_path);
		i++;
		if (i == 0)
			return (NULL);
	}
}
